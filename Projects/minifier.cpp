#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

// ---------- HTML COMMENT REMOVAL ----------
std::string removeHtmlComments(const std::string &html) {
    std::string out;
    bool inComment = false;

    for (size_t i = 0; i < html.size(); i++) {
        if (!inComment && html.substr(i, 4) == "<!--") {
            inComment = true;
            i += 3;
            continue;
        }
        if (inComment && html.substr(i, 3) == "-->") {
            inComment = false;
            i += 2;
            continue;
        }
        if (!inComment)
            out.push_back(html[i]);
    }
    return out;
}

// ---------- CSS COMMENT REMOVAL ----------
std::string removeCssComments(const std::string &css) {
    std::string out;
    bool inComment = false;

    for (size_t i = 0; i < css.size(); i++) {

        if (!inComment && i + 1 < css.size() &&
            css[i] == '/' && css[i+1] == '*') 
        {
            inComment = true;
            i++;
            continue;
        }
        if (inComment && i + 1 < css.size() &&
            css[i] == '*' && css[i+1] == '/') 
        {
            inComment = false;
            i++;
            continue;
        }

        if (!inComment)
            out.push_back(css[i]);
    }
    return out;
}

// ---------- JS COMMENT REMOVAL ----------
std::string removeJsComments(const std::string &js) {
    std::string out;
    bool inBlockComment = false;
    bool inLineComment = false;

    for (size_t i = 0; i < js.size(); i++) {

        if (inBlockComment) {
            if (i + 1 < js.size() && js[i] == '*' && js[i+1] == '/') {
                inBlockComment = false;
                i++;
            }
            continue;
        }

        if (inLineComment) {
            if (js[i] == '\n') {
                inLineComment = false;
                out.push_back('\n');
            }
            continue;
        }

        if (i + 1 < js.size() && js[i] == '/' && js[i+1] == '*') {
            inBlockComment = true;
            i++;
            continue;
        }

        if (i + 1 < js.size() && js[i] == '/' && js[i+1] == '/') {
            inLineComment = true;
            i++;
            continue;
        }

        out.push_back(js[i]);
    }

    return out;
}

// ---------- WHITESPACE MINIFY ----------
std::string minifyWhitespace(const std::string &text) {
    std::string out;
    bool lastSpace = false;

    for (char c : text) {
        if (c == '\n' || c == '\t' || c == '\r')
            continue;

        if (c == ' ') {
            if (lastSpace) continue;
            lastSpace = true;
        } else {
            lastSpace = false;
        }

        out.push_back(c);
    }

    return out;
}

// ---------- MAIN ----------
int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Usage:\n  ./minify <file.html | file.css | file.js>\n";
        return 1;
    }

    std::string inputFile = argv[1];

    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file.\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // Manual endsWith (compatible with all C++ versions)
    auto endsWith = [&](const std::string &suffix) {
        if (inputFile.size() < suffix.size()) return false;
        return inputFile.compare(inputFile.size() - suffix.size(), suffix.size(), suffix) == 0;
    };

    bool isHTML = endsWith(".html");
    bool isCSS  = endsWith(".css");
    bool isJS   = endsWith(".js");

    if (!isHTML && !isCSS && !isJS) {
        std::cerr << "Error: File must end with .html, .css, or .js\n";
        return 1;
    }

    // Minify based on type
    if (isHTML)
        content = removeHtmlComments(content);
    else if (isCSS)
        content = removeCssComments(content);
    else if (isJS)
        content = removeJsComments(content);

    content = minifyWhitespace(content);

    // Output filename
    std::string outputFile = inputFile + ".minified";
    if (isHTML) outputFile += ".html";
    if (isCSS)  outputFile += ".css";
    if (isJS)   outputFile += ".js";

    // Write result
    std::ofstream out(outputFile);

    // Add 1000 empty lines
    for (int i = 0; i < 1000; i++) {
        out << "\n";
    }

    // Then write minified content
    out << content;

    std::cout << "Minified file created with 1000 blank lines: " << outputFile << "\n";
    return 0;
}
