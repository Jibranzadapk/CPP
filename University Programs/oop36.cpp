//ambigious function calll

#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////

class A
{
	public:
	void func(); 
};

void A :: func(){
	int i=5;
}
class B : public A
{ };

class C : public A
{ };

class D : public B, public C
{ };

////////////////////////////////////////////////////////////////
int main()
{
	B objD;
	objD.func(); //ambiguous: won’t compile
	return 0;
}
