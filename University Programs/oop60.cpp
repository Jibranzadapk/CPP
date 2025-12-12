//chap 14 starts
//Templates and Exceptions

//without Function Templates

int abs(int n) //absolute value of ints
{
return (n<0) ? -n : n; //if n is negative, return -n
}

long abs(long n) //absolute value of longs
{
return (n<0) ? -n : n;
}

float abs(float n) //absolute value of floats
{
return (n<0) ? -n : n;
}

