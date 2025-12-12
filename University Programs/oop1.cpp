#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
private:
    string name;

protected:
    int age;

public:
    Person(string n, int a) {
        this->name = n;  // this pointer
        this->age = a;
    }

    void printPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    // Function overloading
    void greet() {
        cout << "Hello, I am " << name << endl;
    }

    void greet(string prefix) {
        cout << prefix << " " << name << endl;
    }

    // Virtual function for overriding
    virtual void greetRole() {
        cout << "I am just a person." << endl;
    }
};

// Derived class
class BankAccount : public Person {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(string n, int a, int accNo, double bal) 
        : Person(n, a) {  // call base constructor
        this->accountNumber = accNo;
        this->balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void printInfo() {
        printPersonInfo();   // print base class info
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // Function overriding
    void greetRole() override {
        cout << "I am a Bank Account holder." << endl;
    }
};

int main() {
    cout << "---- Person Info ----" << endl;
    Person p("Alice", 30);
    p.printPersonInfo();
    p.greet();
    p.greet("Hi");

    cout << "\n---- Bank Account Info ----" << endl;
    BankAccount b("Bob", 25, 101, 5000);
    b.printInfo();
    b.deposit(2000);
    b.withdraw(1000);
    b.withdraw(7000); // Insufficient balance
    b.greetRole();    // overridden function

    return 0;
}
