//without Class Templates

class Stack
{
	private:
	int st[MAX]; //array of ints
	int top; //index number of top of stack

	public:
	Stack(); //constructor
	void push(int var); //takes int as argument
	int pop(); //returns int value
};

class LongStack
{
	private:
	long st[MAX]; //array of longs
	int top; //index number of top of stack

	public:
	LongStack(); //constructor
	void push(long var); //takes long as argument
	long pop(); //returns long value
};

