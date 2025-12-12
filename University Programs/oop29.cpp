//Multiple Inheritance
//see oop29pic

class A // base class A
{
};

class B // base class B
{
};

class C : public A, public B // C is derived from A and B
{
};

int main(){
	C obj;
	return 0;
}
