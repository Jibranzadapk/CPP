#include <iostream>
#include <string>
using namespace std;

// Define a class named Fruit
class Fruit {       
  private:             
    string name;   // To store the name of the fruit
    string color;  // To store the color of the fruit

  public:
    // Constructor to initialize name and color when an object is created
    Fruit(string a, string b) {
      name = a;
      color = b;
    }

    // Function to get the fruit name
    string getName() {
      name = "abc";  // (Unnecessary line but kept as in original code)
      return name;
    }

    // Function to get the fruit color
    string getColor() const {
      return color;
    }

    // Function to change the fruit name
    void setName(string a) {
      name = a;
    }

    // Function to change the fruit color
    void setColor(string a) {
      color = a;
    }
};

int main() {
  // Create an object of Fruit with name "Apple" and color "red"
  Fruit myObj("Apple", "red");

  // Display the current name and color
  cout << myObj.getName() << "\n";
  cout << myObj.getColor() << "\n";

  // Change the fruit's name and color using setter functions
  myObj.setName("mango");
  myObj.setColor("yellow");

  // Display the updated name and color
  cout << myObj.getName() << "\n";
  cout << myObj.getColor() << "\n";

  return 0;
}
