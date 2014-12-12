#include<iostream>
#include <stdio.h>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;

class mystring{
	private:
		char* strng;
	public:
		mystring(){
			strng = (char*)malloc(2*sizeof(char));
			strcpy(strng,"");
		}
		~mystring(){
			cout<< "deleting..."<<endl;
			free(strng);
		}

		mystring(const mystring &o){
			int size = strlen(o.strng);
			strng = (char*)malloc((size+1)*sizeof(char));
			strcpy(strng,o.strng);
		}

		int search(const mystring x){

			char* r=NULL;
			if((r=strstr(strng,x.strng))!=NULL){
				return r-strng;
			}
			else{
				cout<< "SEARCH COMPLETED"<< endl;
				return -1;
			}
		}

		
		void stringcopy(char* x){
			int size = strlen(x);
			
			strng = (char*)realloc(strng,size+1);
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

			int i,n,k;
			n = strlen(strng);
			char* a = (char*)malloc(n*sizeof(char));
			strcpy(a,strng);

			char* r = NULL;
			n=strlen(x);
			for(i=0; strcmp(a,"")!=0;i++){
				if(	(r = strstr(a,x))!=NULL){
					k = r-a;

					char* res = (char*)malloc((k+1)*sizeof(char));
					strncpy(res,a,k);
					res[k]=0;
					if(strcmp(res,"")!=0){

						result[i].stringcopy(res);
					}
					strcpy(a, r+n);
					free(res);

				}
				else{

				//	if(strcmp(a,"")!=0){
						result[i].stringcopy(a);
						i++;
				//	}
				//	else i--;
				   	break;
				}

			}	
			free(a);
			return i;
		}


		int countsplit(char *x){

			int i,n,k;
			n = strlen(strng);
			char* a = (char*)malloc(n*sizeof(char));
			strcpy(a,strng);

			char* r = NULL;
			n=strlen(x);
			for(i=0; strcmp(a,"")!=0;i++){
				if(	(r = strstr(a,x))!=NULL){
					k = r-a;

					//char* res = (char*)malloc((k+1)*sizeof(char));
					//strncpy(res,a,k);
					//res[k]=0;
					//if(strcmp(res,"")!=0){

					//	result[i].stringcopy(res);
					//}
					strcpy(a, r+n);
					//free(res);

				}
				else{

				//	if(strcmp(a,"")!=0){
						//result[i].stringcopy(a);
						i++;
				//	}
				//	else i--;
				   	break;
				}

			}	
			free(a);
			return i;
		}








		void printstring(){
			cout<< strng<<endl;
			cout<<endl;
		}

		void stringcat(char* x){
			int parentsize = strlen(strng);
			int catsize = strlen(x);
			strng = (char*)realloc(strng,parentsize + catsize);
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
	/*mystring a,b,c,d;
	int i,r,splitcount;
	char n[]="abyzfgyzrt";
	char o[]="ab";
	char del[]="yz";
	mystring result[5];
	a.stringcopy(n);
	splitcount = a.msplit(del,result);
	a.printstring();
	cout<<"splitcont  "<<splitcount<<endl;

	for(i=0; i<=splitcount ; i++){
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
	

	*/mystring data, pattern;
	data.stringcopy(argv[1]);
	pattern.stringcopy(argv[2]);
	data.getLength();
	pattern.getLength();
	int pos = data.search(pattern);
	printf("pos: %d\n", pos ) ;

	int	splitcount = data.countsplit(argv[2]);
	cout<<"splitcount is "<<splitcount<<endl;

	mystring result[splitcount];
	 splitcount = data.msplit(argv[2],result);
	for (int i = 0 ; i < splitcount ; i++ ) {
		cout<<"result "<<i<< "is...";
		result[i].printstring();	
	}
	data.printstring();
	pattern.printstring();
			
	return 0;
}
