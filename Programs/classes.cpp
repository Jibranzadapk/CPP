#include <iostream>
using namespace std;

class Lamp {
public:
    bool isOn;
    void turnOn() { isOn = true; }
    void turnOff() { isOn = false; }
    void showStatus() {
        if (isOn)
            cout << "Lamp is ON\n";
        else
            cout << "Lamp is OFF\n";
    }
};

int main() {
    Lamp l1;
    l1.turnOn();
    l1.showStatus();
    l1.turnOff();
    l1.showStatus();
}
