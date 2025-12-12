//operator overloading
// increment counter variable with ++ operator

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
class Counter
{
	private:
		unsigned int count; //count
	public:
		Counter() : count(0) //constructor
		{ }
		
		unsigned int get_count() //return count
		{ return count; }
		
		void operator ++ () //increment (prefix)
		{
		++count;
		}
};
/*
void operator ++ ()
This declarator syntax tells the compiler to call this member function whenever
the ++ operator is encountered, provided the operand is of type Counter.

the only way it can distinguish between overloaded operators is by looking at the
data type of their operands. If the operand is a basic type such as an int, as in
++intvar;
then the compiler will use its built-in routine to increment an int. But if the operand is a
Counter variable, the compiler will know to use our user-written operator++() instead.

program has a subtle defect. You will discover it
if you use a statement like this in main():
c1 = ++c2;
The compiler will complain. Why? Because we have defined the ++ operator to have a return
type of void in the operator++() function
*/
////////////////////////////////////////////////////////////////
int main()
{
	Counter c1, c2; //define and initialize

	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count();

	++c1; //increment c1

	++c2; //increment c2
	++c2; //increment c2

	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count();

//	c1= ++c2;	
	return 0;
}
