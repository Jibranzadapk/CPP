#include<iostream>
using namespace std;
class A{
	public :
	int print()
	{
	cout<<"Hello from A";
	return 0;
}
};
class B:public A{
	public :
	int printb()
	{
	cout<<"Hello from B";
	return 0;
	}
};
class C{
	public :
	int printb()
	{
	cout<<"Hello from C";
	return 0;
	}
};
class E:public A{
        public :
        int printe()
        {
        cout<<"Hello from E";
        return 0;
        }
};

class  D:public B,  public C, public E{
	public:
	int printd()
	{
	cout<<"Hello from D";
	return 0;
	}
};
int main(){
	D d;
	d.printc();

	return 0;
}
