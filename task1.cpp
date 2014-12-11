#include<iostream>
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

		void search(const mystring x){
			int i,n,t;
			n= strlen(x.strng);
			char tmp[10];
		//	cout<<"<<n is"<<n<<endl;

			for(i=0; strng[i]!=0 ;i++){
				strncpy(tmp,strng+i,n);
				
				tmp[n]=0;
				t=strlen(tmp);
				//cout<<"t is.."<<t<<endl;

				
				//cout<<"tmp>>>"<<tmp<<endl;
				if(t!=n)
					break;
				if(strcmp(tmp,x.strng)==0){
					cout<<"similar strings..found at "<< i <<endl;
				}
			}
			cout<< "SEARCH COMPLETED"<< endl;
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



		void printstring(){
			cout<< strng<<endl;
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

int main(){
	mystring a;
	char n[]="tiljot";
	char o[]="iljotr";
	a.stringcopy(n);

	mystring t2;
	t2.stringcopy(o);

	//t2 = a;
	a.search(t2);

	/*mystring t3;
	t3 = a+t2;
	t3.stringcopy(o);
	a.search(t3);
	cout<< "---->searched in a"<<endl;
	cout<< "t3 is..."<<endl;

	t3.printstring();
	cout<< "t2 is..."<< endl;
	t2.printstring();
	t2.stringcopy(o);
	t2.printstring();
	a.getLength();
	a.printstring();
	a.toUpper();
	a.printstring();*/

	return 0;
}
