// Constant Member Functions Example

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
// Class: Distance
// Represents a distance measurement in feet and inches.
// Demonstrates use of constructors, const member functions,
// and returning objects by value.
////////////////////////////////////////////////////////////////

class Distance {
private:
    int feet;
    float inches;

public:
    // Constructors
    Distance() : feet(0), inches(0.0) { }                 // Default constructor
    Distance(int ft, float in) : feet(ft), inches(in) { } // Parameterized constructor

    // Input and output member functions
    void getdist() {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showdist() const {
        cout << feet << "\'-" << inches << '\"';
    }

    // Adds current Distance object to another and returns the result
    Distance add_dist(const Distance&) const;
};

////////////////////////////////////////////////////////////////
// Function: add_dist
// Purpose : Adds the invoking Distance object with another Distance.
// Returns : A new Distance object containing the sum.
////////////////////////////////////////////////////////////////

Distance Distance::add_dist(const Distance& d2) const {
    Distance temp; // Temporary object to hold the result

    // Add the inches part first
    temp.inches = inches + d2.inches;

    // If total inches exceed 12, adjust feet and inches accordingly
    if (temp.inches >= 12.0) {
        temp.inches -= 12.0;
        temp.feet = 1;
    }

    // Add total feet from both distances (including any carry)
    temp.feet += feet + d2.feet;

    return temp; // Return the resulting distance
}

////////////////////////////////////////////////////////////////
// Main Function
// Demonstrates creation, input, and addition of Distance objects.
////////////////////////////////////////////////////////////////

int main() {
    Distance dist1, dist3;           // Objects for user input and result
    Distance dist2(11, 6.25);        // Predefined distance

    dist1.getdist();                 // Get first distance from user
    dist3 = dist1.add_dist(dist2);   // Compute sum of two distances

    // Display all distances
    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << "\ndist3 = "; dist3.showdist();
    cout << endl;

    return 0;
}
