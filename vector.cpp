#include<iostream>
using namespace std;

void printvector(double x0, double x1, double y0, double y1){
	cout << "(" << x0 << "," << y0 << ")"<< "("<< x1 << "," << y1 << ")"<< endl;
}

void offsetvector(double &x0, double &x1, double &y0, double &y1, double xoffset, double yoffset)
{
	x0 += xoffset;
	x1 += xoffset;
	y0 += yoffset;
	y1 += yoffset;
}

int main()
{
	double x0 = 1.1;
	double x1 = 2.0;
	double y0 = 4.2;
	double y1 = 3.1;
	
	double xoffset = 10.5;
	double yoffset = 0.5;
	printvector(x0,x1,y0,y1);
	offsetvector(x0,x1,y0,y1,xoffset,yoffset);
	printvector(x0,x1,y0,y1);

	return 0;
}

