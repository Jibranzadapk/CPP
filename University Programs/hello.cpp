#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class employee{
	protected:
	int age;
	public: 
	int getAge(){
		return age;
	}
	void setAge(int a){
		age=a;
	}
};

class boss: public employee{
	int b;
	public: 
	void setAge(int a){
		b=a+5;
	}
};


int main() {
	boss e1;
	int a;
	cin>>a;
	e1.setAge(a);
	cout<<e1.getAge();
	return 0;
}
