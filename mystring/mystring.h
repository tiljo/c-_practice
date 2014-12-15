#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cassert>
using namespace std;

class mystring{
	private:
		char* str_ptr;
	public:

		mystring();
		~mystring();
		mystring(const mystring &o);
		int search(const mystring& x);
		void stringcopy(char* x);
		int getLength();
		void toLower();
		void toUpper();
		int msplit(char *x,mystring* result);
		int countsplit(char *x);
		void printstring();
		void stringcat(char* x);
		void operator=(const mystring &x);
		mystring operator+(const mystring &x);
		
};

