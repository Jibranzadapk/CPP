#include <iostream>
#include <string>
using namespace std;

class Fruit {       // The class
  public:             // Access specifier
    string name;        // Attribute (int variable)
    string color;  // Attribute (string variable)
};

int main() {
  Fruit myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.name = "mango";
  myObj.color = "yellow";

  Fruit abc;  // Create an object of MyClass

  // Access attributes and set values
  abc.name = "grapes";
  abc.color = "green";

  // Print values
  cout << myObj.name << "\n"; 
  cout << myObj.color<< "\n"; 
  
  // Print values
  cout << abc.name << "\n"; 
  cout << abc.color<< "\n"; 
  
  return 0;
}
