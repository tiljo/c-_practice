#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stdio.h>
using namespace std;

class student{
	private:
		char* name ;//fields set
		int id;
	public://we use public methods to access private fields
		student(){//default  constructor
			
			name = (char*)malloc(10*sizeof(char));
			strcpy(name,"");
			id = 0;
		}
		~student(){//destructor
			cout << "object is being deleted"<< endl;
			cout << &name<<endl;
			printf("---->%p\n",name);
			free(name);
		}
		student( student &o){//custom copy constructor which invoked during 'initialisation' of new class with old one;
			cout << "in construdctor " << endl; 
		
			name = (char*)malloc(10*sizeof(char));
			strcpy(name,o.name);
			id = o.id;
		}

		void printfields(){//print private fields
			cout << "name is: "<< name << " id is:"<< id<<endl;
			cout << &name<<endl;
			cout<<endl;
		}

		void cpyfields(char *newname, int newid){//assigning new name and id to private fields
			strcpy(name,newname);
			id = newid;
		}
		void stringcat(char* newname){//strcat to private field
			strcat(name,newname);
		}
		/*student operator+(student &o){
			student temp;
			 strcat(this->name,o.name);
			 temp.stringcat(this->name);
			temp.id = this->id+o.id;
			return temp;
		}

		void operator=(student &obj){
			strcpy(name,obj.name);
			id = obj.id;
		}*/
		
};

int main()
{
	student t1;//create new instance using constructor;
	char name[]="tiljo";
	char name2[] = "silo";
	char last[]="tr";
	int id = 176;
	t1.printfields();

	t1.cpyfields(name,id);
	t1.printfields();
	cout << "after appending last"<<endl;

	t1.stringcat(last);
	t1.printfields();

	student t2  = t1;//invokes custom constructor
//	student t3;
   cout<<"-----------------------"	<<endl;
	t2.printfields();
   
	//t2 = t2; //use this line only after '=' operator overloading, otherwise cause memory leak;

	//t2.printfields();
	
	
	cout << "after doing student t2=t1"<<endl;
	cout << "t2..is.."<<endl;
	t2.printfields();
	
	//t2 =t1;

//	t2.printfields();
	cout << "after giving 'silo' to t2"<<endl;
	t2.cpyfields(name2,7);

	t2.printfields();
	cout<<"t1 is.."<<endl;
	t1.printfields();

	 //t3 =t1+t2;
	cout<<"t3 is"<<endl;
	//t3.printfields();


//	while(1);
	//t2[4] = 'i';

	return 0;
}

