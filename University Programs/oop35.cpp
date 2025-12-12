#include<iostream>
#include "Date.h"

int main(){
    Date date;
    int input;

    cout << "Enter day: " << endl;
    cin >> input;
    date.setDay(input);
    cout << "Enter month: " << endl;
    cin >> input;
    date.setMonth(input);
    cout << "Enter year: " << endl;
    cin >> input;
    date.setYear(input);

    date.displayDate();
}
