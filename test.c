#include<stdio.h>
#include<string.h>

int main()
{
	
	char a[]="hello";
	char b[]="world";

	strcat(a,b);
	printf("%s\n",a);
	return 0;
}
