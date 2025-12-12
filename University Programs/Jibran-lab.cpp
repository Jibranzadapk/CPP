#include<iostream>
#include <string>
using namespace std;
 
 class A{
 	string name="Jibran";
 	int age=19;
 
 public:
 	 char add(char a, char b){
    return a;
 	}

 	int display(){
    cout<<"\t"<<age<<endl;
    return 0;
 	}
 
 };

  main(){
 		A obj;
 		cout<<obj.add('A','B');
 		obj.display();
 };
