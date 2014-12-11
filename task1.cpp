#include<iostream>
#include <stdio.h>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;

class mystring{
	char* strng;
	public:
		mystring(){
			strng = (char*)malloc(10*sizeof(char));
			strcpy(strng,"");
		}
		~mystring(){
			cout<< "deleting..."<<endl;
			free(strng);
		}

		mystring(const mystring &o){
			strng = (char*)malloc(10*sizeof(char));
			strcpy(strng,o.strng);
		}

		int search(const mystring x){
			int i,n,t;
			n= strlen(x.strng);
			char tmp[10];

			for(i=0; strng[i]!=0 ;i++){
				strncpy(tmp,strng+i,n);
				
				tmp[n]=0;
				t=strlen(tmp);

				if(t!=n)
					break;
				if(strcmp(tmp,x.strng)==0){
					cout<<"similar strings..found at "<< i <<endl;
					return i;
				}
			}
			cout<< "SEARCH COMPLETED"<< endl;
			return -1;
		}

		
		void stringcopy(char* x){
			strcpy(strng,x);
		}

		void getLength(){
			cout<< "string length is.."<< strlen(strng)<<endl;
		}

		void toLower(){
			int i;
			for(i=0; i<strlen(strng);i++){
				strng[i] = tolower(strng[i]);
			}
			strng[i]=0;
		}


		void toUpper(){
			int i;
			for(i=0; i<strlen(strng);i++){
				strng[i] = toupper(strng[i]);
			}
			strng[i]=0;
		}

		int msplit(char *x,mystring result[10]){
			char* token;
			char t[10];
			int i=0;

			char tmp[10];//store the string to split in tmp
			strcpy(tmp,strng);
			token = strtok(tmp,x);
			while(token!=NULL){
				strcpy(t,token);
				result[i].stringcopy(t);i++;
				token = strtok(NULL,x);
			}

			return i;

		}

		void printstring(){
			cout<< strng<<endl;
			cout<<endl;
		}

		void stringcat(char* x){
			strcat(strng,x);
		}

		void operator=(const mystring &x){
			strcpy(strng,x.strng);
		}

		mystring operator+(const mystring &x){
			mystring temp;
			strcpy(temp.strng,this->strng);
			strcat(temp.strng,x.strng);
			return temp;
		}

		
};

int main(int argc, char *argv[]){
/*	mystring a;
	int i,r,splitcount;
	char n[]="abyzfgyzrt";
	char o[]="ab";
	char del[]="yz";
	mystring result[5];
	a.stringcopy(n);
	splitcount = a.msplit(del,result);
	a.printstring();

	for(i=0; i<splitcount ; i++){
		result[i].printstring();
	}

	mystring t2;
	t2.stringcopy(o);

	r = a.search(t2);
	a.printstring();
	t2.printstring();
	cout<<"........."<<r<<endl;

	mystring t3;
	t3 = a+t2;
	cout<<"t3 is..."<<endl;
	t3.printstring();

	cout<< "t2 is..."<< endl;
	t2.printstring();
	a.getLength();
	a.printstring();
	a.toUpper();
	a.printstring();
*/
	mystring data, pattern;
	data.stringcopy(argv[1]);
	pattern.stringcopy(argv[2]);
	int pos = data.search(pattern);
	printf("pos: %d\n", pos ) ;
	
	mystring result[5];
	int splitcount = data.msplit(argv[2],result);
	for (int i = 0 ; i < splitcount ; i++ ) {
		result[i].printstring();	
	} 
	return 0;
}
