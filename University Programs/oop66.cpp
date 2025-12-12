// demonstrates exceptions

#include <iostream>
using namespace std;
const int MAX = 3; //stack holds 3 integers

////////////////////////////////////////////////////////////////
class Stack
{
	private:
	int st[MAX]; //array of integers
	int top; //index of top of stack

	public:
	class Range //exception class for Stack
	{ //note: empty class body
	
		//All we really need in this simple example is the class name, Range.
		//This name is used to connect a throw statement with a catch block. 
		//The class body need not always be empty
	};

	Stack() //constructor
	{ top = -1; }

	void push(int var)
	{
		if(top >= MAX-1) //if stack full,
		throw Range(); //throw exception
		st[++top] = var; //put number on stack
	}

	int pop()
	{
		if(top < 0) //if stack empty,
		throw Range(); //throw exception
		return st[top--]; //take number off stack
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	Stack s1;
	
	try
	{
		s1.push(11);
		s1.push(22);
		s1.push(33);
		//s1.push(44);
	} //oops: stack full

	catch(Stack::Range) //exception handler
	{
		cout << "Exception: Stack Full or Empty" << endl;
	}

	try
	{
		cout << "1:" << s1.pop() << endl;
		cout << "2:" << s1.pop() << endl;
		cout << "3:" << s1.pop() << endl;
		cout << "4:" << s1.pop() << endl; //oops: stack empty
	}

	catch(Stack::Range) //exception handler
	{
		cout << "Exception: Stack Full or Empty" << endl;
	}

	cout << "Arrive here after catch (or normal exit)" << endl;
	return 0;
}
