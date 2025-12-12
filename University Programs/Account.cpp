#include<string>
#include <iostream>
using namespace std;

class Account{
    public:
        Account(double initialBalance){
            if(initialBalance > 0){
                balance = initialBalance;
            }
            else cerr<<"the initial balance was invalid"<<endl;
        }
        void credit(int depositAmount){
            if(depositAmount > 0){
                balance = balance + depositAmount;
                cout<<"credited"<<endl;
                cout << "\n new balance is "<<balance<<endl;
            }
        }
       
        //function that withdraws only valid amount of 
        //money from account
        bool debit(int withdrawAmmount){
            if(withdrawAmmount > balance){
                cout << "Debit amount exceeded account balance."<<endl;
                return false;
            }
            balance = balance - withdrawAmmount;
            cout << withdrawAmmount << " withdrawed."<<endl;
            cout << "\n new balance is "<<balance<<endl;
            return true;
        }
    protected:
        double balance;
};

class RoshanPakistanAccount: public Account{
	private:
	string currencyName;
	
	public:
	RoshanPakistanAccount(string cName, double initialBalance): 
				Account(initialBalance) {
            currencyName=cName;
            cout <<" foreign currency is set to "<<cName<<endl;
        	}		
};

class CurrentAccount: public Account{
	
	private:	
	double transFee;
	
	public:
	CurrentAccount(double fee, double initialBalance): Account(initialBalance) {
            transFee=fee;
        	}
        	
        	void credit(int depositAmount){
          	if(depositAmount > 0){
                		Account::credit(depositAmount);
                		balance = balance - transFee;
                		cout << "\n after deducing transFee new balance is "<<balance<<endl;
                	}
          }
          
          void debit(int withdrawAmmount){
            if (Account::debit(withdrawAmmount)){
	          balance = balance - transFee;
	          cout << "\n after deducing transFee new balance is "<<balance<<endl;	            
	  }
          }
};

int main(){

    cout <<"\n\n object a1 of Account class"<<endl; 	
    Account a1(50);
    cout << "Enter amount you want to withdraw: " << endl;
    int withdrawAmmount;
    cin >> withdrawAmmount;
    a1.debit(withdrawAmmount);    

    cout <<"\n\n object a2 of Account class"<<endl;
    Account a2(-5);

	cout <<"\n\n object a3 of RoshanPakistanAccount class"<<endl;
	RoshanPakistanAccount a3("Riyal", 500);
	    cout << "Enter amount you want to withdraw: " << endl;
	    cin >> withdrawAmmount;
	    a3.debit(withdrawAmmount);    
	
	cout <<"\n\n object a4 of CurrentAccount class"<<endl;
	CurrentAccount a4(5,100);
	    cout << "Enter amount you want to withdraw: " << endl;
	    cin >> withdrawAmmount;
	    a4.debit(withdrawAmmount);    
	
	    cout << "Enter amount you want to deposit: " << endl;
	    int deposit;
	    cin >> deposit;
	    a4.credit(deposit);    
	
}

