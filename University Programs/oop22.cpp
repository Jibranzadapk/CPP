// inheritance

#include <iostream>
using namespace std;
// ================================ Inheritance program ==========================

class Counter //base class
{
	protected: //NOTE: not private
		unsigned int count; //count
	
	public:
		Counter() : count(0) //no-arg constructor
		{ }
		
		Counter(int c) : count(c) //1-arg constructor
		{ }
		
		unsigned int get_count() const //return count
		{ return count; }
		
		Counter operator ++ () //incr count (prefix)
		{ return Counter(++count); }
};

////////////////////////////////////////////////////////////////
class CountDn : public Counter //derived class      public-inheritance
{
	public:
		Counter operator -- () //decr count (prefix)
		{ return Counter(--count); }
};

/*
The keyword public specifies that objects of the derived class are able to access
public member functions of the base class. 

The alternative is the keyword private. 

When this keyword is used, objects of the derived class cannot access public member functions of the
base class. 
*/

////////////////////////////////////////////////////////////////
int main()
{
	CountDn c1; //c1 of class CountDn
	
	cout << "\nc1=" << c1.get_count(); //display c1
	
	++c1; ++c1; ++c1; //increment c1, 3 times
	cout << "\nc1=" << c1.get_count(); //display it
	
	--c1; --c1; //decrement c1, twice
	cout << "\nc1=" << c1.get_count(); //display it
	
	Counter abc;
	++abc;
	--abc;
	cout << endl;
	return 0;
}

