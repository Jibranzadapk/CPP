#include<iostream>
using namespace std;
    int main() {
     int a;
     int b;
     int operation;
     int output;
     cout<<"--------------------  Calculator ---------------------"<<endl;
     cout<<"\nEnter 1st number : ";
     cin>>a;
     cout<<"\nEnter 2nd number : ";
     cin>>b;
     cout<<"1 = Addition"<<endl;
     cout<<"2 = Subtraction"<<endl;
     cout<<"3 = Division"<<endl;
     cout<<"4 = Multiplication"<<endl;
     cout<<"Choose the operator : ";
     cin>>operation;
     if(operation==1)
     {
      output=a+b;
      cout<<"Sum of your numbers are :"<<output<<endl;
     }
     else if(operation==2)
     {
     output=a-b;
     cout<<"Subtraction of your numbers are : "<<output<<endl;
     }
     else if(operation==3)
     {
     output=a/b;
     cout<<"Division of your numbers are : "<<output<<endl;
     }
     else if(operation==4)
     {
     output=a*b;
     cout<<"Multiplication of your numbers are : "<<output<<endl;
     }
     else
     cout<<"Invalid operator";
     return 0;
}
