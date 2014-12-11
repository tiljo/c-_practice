#include<iostream>
using namespace std;

class point{
	public:
		double x;
		double y;

		void offset(double offx, double offy);
		void print();
};

class vector{
	public:
		point start;
		point end;

		void offset(double offx, double offy);
		void print();
};

void point::offset(double offx, double offy){
	x +=offx; y += offy;
}

void point::print(){
	cout<< "("<< x << "," << y << ")";
}

void vector::offset(double offx, double offy){
	start.offset(offx,offy);
	end.offset(offx,offy);
	
}

void vector::print(){
	start.print();
	cout << "->" ;
	end.print();
	cout <<endl;
}
int main()
{
	vector v1;
	v1.start.x =1;
	v1.start.y =2;
	v1.end.x =5;
	v1.end.y =10;

	double offx = 20;
	double offy = 30;


	v1.print();
	v1.offset(offx,offy);
	v1.print();

}




