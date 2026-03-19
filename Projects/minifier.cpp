#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

// ---------- HTML COMMENT REMOVAL ----------
std::string removeHtmlComments(const std::string &html) {
    std::string out;
    bool inComment = false;
    for (size_t i = 0; i < html.size(); i++) {
        if (!inComment && html.substr(i,4) == "<!--") { inComment=true;i+=3; continue; }
        if (inComment && html.substr(i,3) == "-->") { inComment=false;i+=2; continue; }
        if (!inComment) out.push_back(html[i]);
    }
    return out;
}

// ---------- CSS COMMENT REMOVAL ----------
std::string removeCssComments(const std::string &css) {
    std::string out;
    bool inComment=false;
    for(size_t i=0;i<css.size();i++){
        if(!inComment && i+1<css.size() && css[i]=='/' && css[i+1]=='*'){inComment=true;i++;continue;}
        if(inComment && i+1<css.size() && css[i]=='*' && css[i+1]=='/'){inComment=false;i++;continue;}
        if(!inComment) out.push_back(css[i]);
    }
    return out;
}

// ---------- JS COMMENT REMOVAL ----------
std::string removeJsComments(const std::string &js) {
    std::string out;
    bool inBlock=false, inLine=false;
    for(size_t i=0;i<js.size();i++){
        if(inBlock){if(i+1<js.size() && js[i]=='*' && js[i+1]=='/'){inBlock=false;i++;}continue;}
        if(inLine){if(js[i]=='\n'){inLine=false;out.push_back('\n');}continue;}
        if(i+1<js.size() && js[i]=='/' && js[i+1]=='*'){inBlock=true;i++;continue;}
        if(i+1<js.size() && js[i]=='/' && js[i+1]=='/'){inLine=true;i++;continue;}
        out.push_back(js[i]);
    }
    return out;
}

// ---------- MINIFY WHITESPACE ----------
std::string minifyWhitespace(const std::string &text) {
    std::string out;
    bool lastSpace=false;
    for(char c:text){
        if(c=='\n'||c=='\t'||c=='\r') continue;
        if(c==' '){if(lastSpace) continue; lastSpace=true;} else lastSpace=false;
        out.push_back(c);
    }
    return out;
}

// ---------- INLINE CSS/JS MINIFY FOR HTML ----------
std::string minifyInlineHtml(const std::string &html){
    std::string out;
    size_t i=0;
    while(i<html.size()){
        if(i+7<html.size() && html.substr(i,7)=="<script"){
            size_t endTag=html.find("</script>",i);
            if(endTag==std::string::npos) endTag=html.size();
            size_t startContent=html.find('>',i);
            if(startContent!=std::string::npos && startContent<endTag){
                std::string scriptContent=html.substr(startContent+1,endTag-startContent-1);
                scriptContent=removeJsComments(scriptContent);
                scriptContent=minifyWhitespace(scriptContent);
                out+=html.substr(i,startContent-i+1);
                out+=scriptContent;
                out+="</script>";
                i=endTag+9;
                continue;
            }
        }
        if(i+6<html.size() && html.substr(i,6)=="<style"){
            size_t endTag=html.find("</style>",i);
            if(endTag==std::string::npos) endTag=html.size();
            size_t startContent=html.find('>',i);
            if(startContent!=std::string::npos && startContent<endTag){
                std::string styleContent=html.substr(startContent+1,endTag-startContent-1);
                styleContent=removeCssComments(styleContent);
                styleContent=minifyWhitespace(styleContent);
                out+=html.substr(i,startContent-i+1);
                out+=styleContent;
                out+="</style>";
                i=endTag+8;
                continue;
            }
        }
        out.push_back(html[i]);
        i++;
    }
    return out;
}

// ---------- HELPER: endsWith ----------
bool endsWith(const std::string &str,const std::string &suffix){
    if(str.size()<suffix.size()) return false;
    return str.compare(str.size()-suffix.size(),suffix.size(),suffix)==0;
}

// ---------- PROCESS SINGLE FILE ----------
void processFile(const std::string &inputFile,int emptyLines,const std::string &customOutput,bool skipEmpty){
    std::ifstream file(inputFile);
    if(!file.is_open()){std::cerr<<"Cannot open file: "<<inputFile<<"\n"; return;}
    std::stringstream buffer; buffer<<file.rdbuf(); std::string content=buffer.str();

    bool isHTML=endsWith(inputFile,".html");
    bool isCSS=endsWith(inputFile,".css");
    bool isJS=endsWith(inputFile,".js");
    if(!isHTML && !isCSS && !isJS){std::cerr<<"Unsupported file: "<<inputFile<<"\n"; return;}

    // minify
    if(isHTML) {content=removeHtmlComments(content); content=minifyInlineHtml(content);}
    else if(isCSS) content=removeCssComments(content);
    else if(isJS) content=removeJsComments(content);

    content=minifyWhitespace(content);

    // output filename
    std::string outputFile=customOutput.empty()?inputFile+".minified":customOutput;
    if(customOutput.empty()){
        if(isHTML) outputFile+=".html";
        if(isCSS) outputFile+=".css";
        if(isJS) outputFile+=".js";
    }

    std::ofstream out(outputFile);
    if(!skipEmpty){
        for(int i=0;i<emptyLines;i++) out<<"\n";
    }
    out<<content;

    // stats
    std::ifstream orig(inputFile,std::ios::binary|std::ios::ate);
    size_t origSize=orig.tellg();
    size_t minSize=content.size()+(skipEmpty?0:emptyLines);
    double percent=(1.0-((double)minSize/(double)origSize))*100.0;
    std::cout<<"Processed: "<<inputFile<<"\nOriginal: "<<origSize<<" bytes\nMinified: "<<minSize<<" bytes\nCompression: "<<percent<<"%\nOutput: "<<outputFile<<"\n\n";
}

// ---------- PROCESS FOLDER ----------
void processFolder(const std::string &folder,int emptyLines,const std::string &customOutput,bool skipEmpty){
    for(auto &p:fs::directory_iterator(folder)){
        if(p.is_regular_file()){
            std::string path=p.path().string();
            if(endsWith(path,".html")||endsWith(path,".css")||endsWith(path,".js")){
                processFile(path,emptyLines,customOutput,skipEmpty);
            }
        }
    }
}

// ---------- MAIN ----------
int main(int argc,char* argv[]){
    if(argc<2){std::cout<<"Usage: ./minify [options] <file_or_folder>\n"
                        "--lines N      : prepend N empty lines (default 1000)\n"
                        "--output name  : custom output filename\n"
                        "--no-empty     : skip empty lines\n"
                        "--folder path  : minify all files in folder\n"
                        "--help         : show this help\n"; return 0;}

    int emptyLines=1000;
    std::string customOutput="";
    bool skipEmpty=false;
    std::string target="";
    bool folderMode=false;

    for(int i=1;i<argc;i++){
        std::string arg=argv[i];
        if(arg=="--lines" && i+1<argc){emptyLines=std::stoi(argv[++i]);}
        else if(arg=="--output" && i+1<argc){customOutput=argv[++i];}
        else if(arg=="--no-empty"){skipEmpty=true;}
        else if(arg=="--folder" && i+1<argc){target=argv[++i]; folderMode=true;}
        else if(arg=="--help"){std::cout<<"Help: see usage above.\n"; return 0;}
        else target=arg;
    }

    if(folderMode) processFolder(target,emptyLines,customOutput,skipEmpty);
    else processFile(target,emptyLines,customOutput,skipEmpty);

    return 0;
}
