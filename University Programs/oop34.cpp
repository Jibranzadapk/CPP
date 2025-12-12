#include<string>
#include <iostream>
#include "Employee.h"

using namespace std;

int main(){
	string input;
	int x;
	Employee first("John", "Dujmovic", 1500);
	Employee second("Joanna", "Smith", 2000);
	
	cout << "Yearly salary of first employee: " << first.getYearlySalary();
	cout << "\nYearly salary of second employee: " << second.getYearlySalary();
	
	cout << "\n10 percent raise." ;
	first.setSalary(first.getSalary()*1.1);
	second.setSalary(second.getSalary()*1.1);
	
	cout << "\nYearly salary of first employee after raise: " << first.getYearlySalary();
	cout << "\nYearly salary of second employee after raise: " << 
	second.getYearlySalary();
}
