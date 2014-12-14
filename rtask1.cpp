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
		mystring(){
			str_ptr = (char*)malloc(2*sizeof(char));
			printf("malloced...%p\n",str_ptr);
			strcpy(str_ptr,"d");
		}
		~mystring(){
			printf("deleting..%p\n",str_ptr);
			free(str_ptr);
		}

		mystring(const mystring &o){
			int size = strlen(o.str_ptr);
			str_ptr = (char*)malloc((size+1)*sizeof(char));
			printf("malloced...in 1 arg..%p\n",str_ptr);
			strcpy(str_ptr,o.str_ptr);
		}

		int search(const mystring& x){

			char* r=NULL;
			if((r=strstr(str_ptr,x.str_ptr))!=NULL){
				return r-str_ptr;
			}
			else{
				cout<< "SEARCH COMPLETED"<< endl;
				return -1;
			}
		}

		
		void stringcopy(char* x){
			int size = strlen(x);
			assert(size>0);
			assert(str_ptr!=NULL);
			if((str_ptr = (char*)realloc(str_ptr,size+1))==NULL){
				perror("realloc");
				exit(1);
			}
			printf("in strcp: reallocd.....%p	\n",str_ptr);
			strcpy(str_ptr,x);

		}

		int getLength(){
			return(strlen(str_ptr));
		}

		void toLower(){
			unsigned int i;
			for(i=0; i<strlen(str_ptr);i++){
				str_ptr[i] = tolower(str_ptr[i]);
			}
			str_ptr[i]=0;
		}


		void toUpper(){
			unsigned int i;
			for(i=0; i<strlen(str_ptr);i++){
				str_ptr[i] = toupper(str_ptr[i]);
			}
			str_ptr[i]=0;
		}

		int msplit(char *x,mystring* result){

			int i=0,n,k;
			n = strlen(str_ptr);
			char* a = (char*)malloc(n*sizeof(char));

			printf("malloced...in msplt tmp a,...%p\n",a);
			strcpy(a,str_ptr);

			char* r = NULL;
			n=strlen(x);
			while(strcmp(a,"")!=0){
				if(	(r = strstr(a,x))!=NULL){
					k = r-a;

					char* res = (char*)malloc((k+1)*sizeof(char));

					printf("malloced for res,...%p\n",res);
					strncpy(res,a,k);
					res[k]=0;
					if(res[0]!=0){

						result[i].stringcopy(res);i++;
					}
					strcpy(a, r+n);
					free(res);

					printf("freeing res..,...%p\n",res);

				}
				else{

						result[i].stringcopy(a);
						i++;
				   		break;
				}

			}	
			free(a);
			printf("freeing  a,...%p\n",a);
			return i;
		}


		int countsplit(char *x){

			int i=0,n;
			n = strlen(str_ptr);
			char* a = (char*)malloc(n*sizeof(char));

			printf("malloc countsplit  a,...%p\n",a);

			strcpy(a,str_ptr);

			char* r = NULL;
			n=strlen(x);
			while(a[0]!=0){
				if(	(r = strstr(a,x))!=NULL){

				if(a!=r)	i++;
				strcpy(a, r+n);

				}
				else{

						i++;
				   		break;
				}

			}	
			free(a);
			printf("freeing in cntsplit  a,...%p\n",a);
			return i;
		}


		void printstring(){
			cout<< str_ptr<<endl;
			cout<<endl;
		}

		void stringcat(char* x){
			int parentsize = strlen(str_ptr);
			int catsize = strlen(x);
			str_ptr = (char*)realloc(str_ptr,parentsize + catsize+2);

			printf("in strcat:  realloc str_ptr,...%p\n",str_ptr);
			strcat(str_ptr,x);
		}

		void operator=(const mystring &x){

			str_ptr = (char*)realloc(str_ptr,(strlen(x.str_ptr)+1));
		
			printf("realloc str_ptr in =,...%p\n",str_ptr);
			strcpy(str_ptr,x.str_ptr);
		}

		mystring operator+(const mystring &x){
			mystring temp;
			temp.stringcopy(this->str_ptr);
			temp.stringcat(x.str_ptr);
			return temp;
		}

		
};

int main(int argc, char *argv[]){

	if(argc<3){
		printf("usage error\n");
		exit(1);
	}
	mystring data, pattern;
	data.stringcopy(argv[1]);
	pattern.stringcopy(argv[2]);
	int l1 = data.getLength();
	cout<<"length of data.."<<l1<<endl;;
	int l2 = pattern.getLength();
	cout<<"length of data.."<<l2<<endl;;
	
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
	mystring c;
	cout<<"--------"<<endl;
	c = pattern;
	c.printstring();
	cout<<"+operator......"<<endl;
	c = data+pattern;
	c.printstring();
	return 0;
}
