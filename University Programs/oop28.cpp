//Multi level Class Hierarchies
// see class diagram in oop28pic 

#include <iostream>
using namespace std;

const int LEN = 80; //maximum length of names

////////////////////////////////////////////////////////////////
class employee //employee class
{
	private:
		char name[LEN]; //employee name
		unsigned long number; //employee number

	public:
	void getdata()
	{
		cout << "\n Enter last name: "; cin >> name;
		cout << "\n Enter number: "; cin >> number;
	}

	void putdata() const
	{
		cout << "\n Name: " << name;
		cout << "\n Number: " << number;
	}
};

////////////////////////////////////////////////////////////////
class manager : public employee //management class
{
	private:
		char title[LEN]; //”vice-president” etc.
		double dues; //golf club dues
		
	public:
		void getdata()
		{
			employee::getdata();
			cout << " Enter title: "; cin >> title;
			cout << " Enter golf club dues: "; cin >> dues;
		}

		void putdata() const
		{
			employee::putdata();
			cout << "\n Title: " << title;
			cout << "\n Golf club dues: " << dues;
		}
};

////////////////////////////////////////////////////////////////
class scientist : public employee //scientist class
{
	private:
		int pubs; //number of publications
	public:
		void getdata()
		{
			employee::getdata();
			cout << " Enter number of pubs: "; cin >> pubs;
		}

		void putdata() const
		{
			employee::putdata();
			cout << "\n Number of publications: " << pubs;
		}
};

////////////////////////////////////////////////////////////////
class laborer : public employee //laborer class
{
};

////////////////////////////////////////////////////////////////
class foreman : public laborer //foreman class
{
	private:
		float quotas; //percent of quotas met successfully
	public:
		void getdata()
		{
			laborer::getdata();
			cout << " Enter quotas: "; cin >> quotas;
		}
		void putdata() const
		{
			laborer::putdata();
			cout << "\n Quotas: "<< quotas;
		}
};
///////
////////////////////////////////////////////////////////////////
int main()
{
	manager m1, m2;
	scientist s1;
	laborer l1;
	foreman f1;

	cout << endl; //get data for several employees
	cout << "\nEnter data for manager 1";
	m1.getdata();

	cout << "\nEnter data for scientist 1";
	s1.getdata();

	cout << "\nEnter data for laborer 1";
	l1.getdata();

	cout << "\nEnter data for foreman 1";
	f1.getdata();
	cout << endl;

	//display data for several employees
	cout << "\nData on manager 1";
	m1.putdata();

	cout << "\nData on scientist 1";
	s1.putdata();

	cout << "\nData on laborer 1";
	l1.putdata();

	cout << "\nData on foreman 1";
	f1.putdata();

	cout << endl;
	return 0;
}	

