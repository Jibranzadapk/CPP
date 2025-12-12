#include <iostream>
#include <string>
using namespace std;

class Fruit {       // The class
  private:             // Access specifier
    string name;        // Attribute (int variable)
    string color;  // Attribute (string variable)

   public:
   	Fruit(string a, string b) : name(a), color(b) { 
	   }
   	
	string getName() const {
   		return name;
	   } 
	string getColor() const {
   		return color;
	   } 
	void setName(string a){
		name=a;
	}
	void setColor(string a){
		color=a;
	}
};

int main() {
  Fruit myObj("Apple", "red");  // Create an object of MyClass

  // Print values
  cout << myObj.getName() << "\n"; 
  cout << myObj.getColor()<< "\n"; 
  

  // Access attributes and set values
  myObj.setName("mango");
  myObj.setColor("yellow");

  // Print values
  cout << myObj.getName() << "\n"; 
  cout << myObj.getColor()<< "\n"; 
  
  return 0;
}
