#include<iostream>
#include<cstring>
using namespace std;

/*class complexno{
	public:
		double re;
		double img;

};*/

class str{
	public:
		char* addstring(char* a, char* b){
			strcat(a,b);
			return a;
	}
};
/*complexno addit(complexno a, complexno b)
{
M
	complexno result;
	result.re = a.re + b.re;
	result.img = a.img + b.img;
	
	return result;
}*/

int main()
{

	char a[] = "hello";
	char b[] = "world";
	char* res;
	 str k;
	 res = k.addstring(a,b);
	 cout << res << endl;


	/*complexno a;
	complexno b;
	complexno k;

	a.re = 1.0;
	a.img = 2.0;

	b.re = 2.0;
	b.img = 1.0;

	k = addit(a,b);
	cout << "re part : " << k.re <<"  img part: " << k.img <<endl;*/
	return 0;
}


