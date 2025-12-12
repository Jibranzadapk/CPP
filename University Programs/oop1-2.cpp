#include <iostream>
using namespace std;

class MyClass {       // The class
//  public:             // Access specifier
    int i;        // Attribute (int variable)
};

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.i = 15;
  
  // Print values
  cout << (myObj.i + 5 )<< "\n"; 
  return 0;
}
