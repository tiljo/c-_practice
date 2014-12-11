#include<iostream>
using namespace std;

class point{
	public:
		double x;
		double y;
};

class vector{
	public:
		point start;
		point end;
};

void printvector(vector v)
{
	cout << "("<< v.start.x << "," << v.start.y << ")"<< "->" << "("<< v.end.x << "," << v.end.y << ")" << endl;
}

void offsetvector(vector &v, double x, double y)
{
	v.start.x += x;
	v.start.y += y;

	v.end.x += x;
	v.end.y += y;
}

int main()
{
	vector v1;

	v1.start.x = 2.5;
	v1.start.y = 3.5;
	v1.end.x = 4.5;
	v1.end.y = 5.5;

	printvector(v1);

	offsetvector( v1,10,5);

	printvector(v1);

	return 0;
}

