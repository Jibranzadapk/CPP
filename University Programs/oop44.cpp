// virtual inheritance
//to share a single common subobject of their Parent

class Parent
{
	protected:
	int basedata;
};

class Child1 : virtual public Parent // shares copy of Parent
{ };			

class Child2 : virtual public Parent // shares copy of Parent
{ };

//keyword virtual in these two classes causes them to share a single common
//subobject of their base class Parent
//When the Child1 and Child2 classes are derived from Parent, 
//each inherits a copy of Parent; this copy is called a subobject.

class Grandchild : public Child1, public Child2
{
	public:
	
	int getdata()
	{ return basedata; } // OK: only one copy of Parent
};

int main(){
	Grandchild g;
	g.getdata();
	
	return 0;
}

