#include <iostream>
#include <string>
using namespace std;

class Fruit {       // The class
  private:             // Access specifier
    string name;        // Attribute (int variable)
    string color;  // Attribute (string variable)

   public:
   	string getName(){
   		return name;
	   } 
	string getColor(){
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
  Fruit myObj;  // Create an object of MyClass

//myObj.name="mango";

  // Access attributes and set values
  myObj.setName("mango");
  myObj.setColor("yellow");

  // Print values
  cout << myObj.getName() << "\n"; 
  cout << myObj.getColor()<< "\n"; 
  
  Fruit myObj2;  // Create an object of MyClass

//myObj.name="mango";

  // Access attributes and set values
  myObj2.setName("pineApple");
  myObj2.setColor("greenish");

  // Print values
  cout << myObj2.getName() << "\n"; 
  cout << myObj2.getColor()<< "\n"; 

  return 0;
}
