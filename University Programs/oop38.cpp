//aggregation

//manager aggregates employee and student objects
//scientist also aggregates employee and student objects
//laborer aggregates employee objectS

//assignment2: chapter 9 is due

#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////

class student //no aggregation
{
	private:
		string school; //name of school or university
		string degree; //highest degree earned
	public:
		void getedu()
		{
			cout << " Enter name of school or university: ";
			cin >> school;
			cout << " Enter highest degree earned \n";
			cout << " (Highschool, Bachelor’s, Master’s, PhD):";
			cin >> degree;
		}
		void putedu() const
		{
			cout << "\n School or university: " << school;
			cout << "\n Highest degree earned: "
			 << degree;
		}
};

////////////////////////////////////////////////////////////////
class employee 	//no aggregation
{
	private:
		string name; //employee name
		unsigned long number; //employee number
	public:
		void getdata()
		{
			cout << "\n Enter last name: "; cin >> name;
			cout << " Enter number: "; cin >> number;
		}
		void putdata() const
		{
			cout << "\n Name: " << name;
			cout << "\n Number: " << number;
		}
};

////////////////////////////////////////////////////////////////
class manager //aggregating student and employee objects
{
	private:
		string title; //”vice-president” etc.
		double dues; //golf club dues
		employee emp; //object of class employee
		student stu; //object of class student
	public:
		void getdata()
		{
			emp.getdata();	//to call a function of emp 
			cout << " Enter title: "; cin >> title;
			cout << " Enter golf club dues: "; cin >> dues;
		//	stu.getedu();	//to call a function of stu 
		}
		void putdata() const
		{
			emp.putdata();	//to call a function of emp 
			cout << "\n Title: " << title;
			cout << "\n Golf club dues: " << dues;
			stu.putedu();	//to call a function of stu 
		}
};

////////////////////////////////////////////////////////////////
class scientist // //aggregating student and employee objects
{
	private:
		int pubs; //number of publications
		employee emp; //object of class employee
		student stu; //object of class student
	public:
		void getdata()
		{
			emp.getdata();	//to call a function of emp 
			cout << " Enter number of pubs: "; cin >> pubs;
			stu.getedu();	//to call a function of stu 
		}
		void putdata() const
		{
			emp.putdata();	//to call a function of emp 
			cout << "\n Number of publications: " << pubs;
			stu.putedu();	//to call a function of stu 
		}
};

////////////////////////////////////////////////////////////////
class laborer // //aggregating employee objects
{
	private: 
	employee emp; //object of class employee
	public:
	void getdata()
	{ emp.getdata(); }	//to call a function of emp 
	void putdata() const
	{ emp.putdata(); }	//to call a function of emp 
};

////////////////////////////////////////////////////////////////
int main()
{
	manager m1;	//also objects of emp and stu 
	scientist s1, s2;	//also objects of emp and stu
	laborer l1;	//also objects of emp
	cout << endl;
	cout << "\nEnter data for manager 1"; //get data for
	m1.getdata(); //several employees
	cout << "\nEnter data for scientist 1";
	s1.getdata(); //several employees
	cout << "\nEnter data for scientist 2";
	s2.getdata(); //several employees
	cout << "\nEnter data for laborer 1";
	l1.getdata();

	cout << "\nData on manager 1";
	m1.putdata(); //several employees
	cout << "\nData on scientist 1";
	s1.putdata(); //several employees
	cout << "\nData on scientist 2";
	s2.putdata();  //several employees
	cout << "\nData on laborer 1";
	l1.putdata();
	cout << endl;
	return 0;
}
