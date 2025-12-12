//aggregation in C++
//has a relationship

//oop37pic



class student
{};

class employee
{};

class manager
{
	student stu; // stu is an object of class student
	employee emp; // emp is an object of class employee
};

class scientist
{
	student stu; // stu is an object of class student
	employee emp; // emp is an object of class employee
};

class laborer
{
	employee emp; // emp is an object of class employee
};
