#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
#include<cstring>

using namespace std;

int main()
{
	int i,j;
	char hello[]="hello";
	char hello1[]="world";
	char& til = hello;
//	srand((unsigned) time(NULL));

	for(i=0;i<15;i++){
		j = rand();
		cout<<"random number: "<<" "<< j<<endl;
		cout << &hello << endl;
		cout << til << endl;
	}
	return 0;
}
