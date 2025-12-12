class Foo
{
	private:
		int data;
	public:
		Foo()  //constructor (same name as class)
		{data=0; }
		~Foo() //destructor (same name with tilde)
		{ cout<<"OK";
			int i=0;
		 }
};
	////////////////////////////////////////////////////////////////
int main()
{
	Foo c1; //define and initialize

	return 0;
}
