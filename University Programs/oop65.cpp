//working summary of excption handling

//The exception mechanism uses three new C++ keywords: 
//throw, catch, and try. 
//Also, we need to create a new kind of entity called an exception class.

// not a working program
////////////////////////////////////////////////////////////////

class AClass //a class
{
	public:
	class AnError //exception class
	{
	};

	void Func() //a member function
	{
	if( /* error condition */ )
		throw AnError(); //throw exception
	}
};
////////////////////////////////////////////////////////////////
int main() //application
{
	try //try block
	{
		AClass obj1; //interact with AClass objects
		obj1.Func(); //may cause error
	}
	catch(AClass::AnError) //exception handler
	{ //(catch block)
		//tell user about error, etc.
	}
	return 0;
}

