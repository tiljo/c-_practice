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
			printf("%p\n",strng);
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

		int getLength(){
			return(strlen(strng));
		}

		void toLower(){
			unsigned int i;
			for(i=0; i<strlen(strng);i++){
				 strng[i] = tolower(strng[i]);
			}
			strng[i]=0;
		}


		void toUpper(){
			unsigned int i;
			for(i=0; i<strlen(strng);i++){
				strng[i] = toupper(strng[i]);
			}
			strng[i]=0;
		}

		int msplit(char *x,mystring result[10]){

			int i=0,n,k;
			n = strlen(strng);
			char* a = (char*)malloc(n*sizeof(char));
			strcpy(a,strng);

			char* r = NULL;
			n=strlen(x);
			while( strcmp(a,"")!=0){

				if(	(r = strstr(a,x))!=NULL){
					k = r-a;
					cout<<strlen(a)<<endl;

					char* res = (char*)malloc((k+1)*sizeof(char));
					strncpy(res,a,k);
					res[k]=0;
					if(res[0]!=0){

						result[i].stringcopy(res);i++;
					}
					strcpy(a, r+n);
					free(res);

				}
				else{

					//if(strcmp(a,"")!=0){
						result[i].stringcopy(a);
						i++;
					//}
				//	else i--;
				   	break;
				}

			}	
			free(a);
			return i;
		}


		int countsplit(char *x){
			int i=0,n,k;
			n = strlen(strng);
			char* a = (char*)malloc(n*sizeof(char));
			strcpy(a,strng);

			char* r = NULL;
			n=strlen(x);
			while( strcmp(a,"")!=0){
				if(	(r = strstr(a,x))!=NULL){
					k = r-a;
					if(k!=0)i++;

					strcpy(a, r+n);

				}
				else{
						i++;
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
			int parent = strlen(strng) ;
			int child = strlen(x) ;	
			//free(strng);
			strng = (char*)realloc( strng,(parent+child));
			
			strcat(strng,x);
		}

		void operator=(const mystring &x){
			strcpy(strng,x.strng);
		}

		mystring operator+(const mystring &x){
			mystring temp;
			temp.stringcopy(this->strng);
			temp.stringcat(x.strng);

			/*int op1 = strlen(this->strng);
			int op2 = strlen(x.strng);

			temp.strng = (char*)realloc(temp.strng,(op1+op2));
			strcpy(temp.strng,this->strng);
			strcat(temp.strng,x.strng);*/
			return temp;
		}

		
};

int main(int argc, char *argv[]){
	if(argc<3){
		printf("usage error: give minimum 2  arguments\n");
		exit(1);
	}
	mystring data, pattern;//creating 2 instances
	data.stringcopy(argv[1]);//method stringcopy
	pattern.stringcopy(argv[2]);
	int l = pattern.getLength();//method getLength
	cout<<"length is.."<<l<<endl;
	pattern.getLength();
	int pos = data.search(pattern);//impliments  method search()
	printf("pos: %d\n", pos ) ;//printing the substring index

	int	splitcount = data.countsplit(argv[2]);//find no.of objects  to be stored as instance
	cout<<"splitcount is "<<splitcount<<endl;

	mystring result[splitcount];//initialize  'splitcount' no.of instance array
	 splitcount = data.msplit(argv[2],result);//method split(), store new instances in result[]
	for (int i = 0 ; i < splitcount ; i++ ) {//printing field of each instance
		cout<<"result "<<i<< "  is...";
		result[i].printstring();	
	}
	mystring newer,adder;
	cout<<"................"<<endl;
	data.printstring();

    newer = data+pattern;// '+' operator overloading
	cout<<"+ overloading"<<endl;
	newer.printstring();
	newer = pattern;//'='operator overloading
	cout<<"= overloded"<<endl;
	newer.printstring();
			
	return 0;
}
