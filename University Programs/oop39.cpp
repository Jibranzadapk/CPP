//chap 11 starts

//Normal Member Functions Accessed with Pointers

//problems faced during polymorphism:
// accessing objects of different classes using the identically same statement.

// late binding or dynamic binding.
// early binding or static binding

#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////

class Base //base class
{
	public:
		//function called when a virtual function is invoked 
		//depends on the actual type of the object at runtime, 
		//rather than the declared type.
		
		 void show() = 0;//normal function
		//{ cout << "Base\n"; }
};

////////////////////////////////////////////////////////////////
class Derv1 : public Base //derived class 1
{
	public:
		void show()
		{ cout << "Derv1\n"; }
};

////////////////////////////////////////////////////////////////
class Derv2 : public Base //derived class 2
{
	public:
		void show()
		{ cout << "Derv2\n"; }
};
////////////////////////////////////////////////////////////////
int main()
{
	Derv1 dv1; //object of derived class 1
	Derv2 dv2; //object of derived class 2
	
	Base* ptr; //pointer to base class for common reference
	ptr = &dv1; //put address of dv1 in pointer
	(*ptr).show(); //execute show() of parent
	
	ptr = &dv2; //put address of dv2 in pointer
	ptr->show(); //execute show() of parent
	
//	dv1.show();
//	dv2.show();
	
	Base b;
//	b.show();

	ptr = &b; //put address of dv1 in pointer
//	(*ptr).show(); //execute show() of parent
	
	return 0;
}
