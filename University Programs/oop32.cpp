//#include <iostream>
#include "Account.h"

using namespace std;

int main(){
    Account account1("Jane Green", 50) ;

    cout << "Enter amount you want to withdraw: " << endl;
    int withdrawAmmount;
    cin >> withdrawAmmount;
    account1.withdraw(withdrawAmmount);
    cout << "\n new balance is "<<account1.getBalance();
}
