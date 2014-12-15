#include"mystring.h"
#include"mystring.cpp"

int main(int argc, char *argv[]){

	if(argc<3){
		printf("usage error: give 2 arguments\n");
		exit(1);
	}
	
	mystring data, pattern;//creating 2 instance data & pattern
	data.stringcopy(argv[1]);//copying argv1 to data
	pattern.stringcopy(argv[2]);//copying argv2 to pattern


	int l1 = data.getLength();
	cout<<"length of data.."<<l1<<endl;;//fnding the length of data,pattern
	int l2 = pattern.getLength();
	cout<<"length of pattern.."<<l2<<endl;;
	
	int pos = data.search(pattern);// search for pattern in data & print its position
	cout<<"pattern found at pos: "<<pos<<endl;

	int	splitcount = data.countsplit(argv[2]);//finding the no.of instances that remain after splitting using method countsplit
	cout<<"splitcount is "<<splitcount<<endl;

	mystring result[splitcount];//initialising instance array

	splitcount = data.msplit(argv[2],result);//spliting the data based on string and store the instances in array result[]

	for (int i = 0 ; i < splitcount ; i++ ) {//printing all instances formed after split
		cout<<"result "<<i<< " is...";
		result[i].printstring();
	}

	mystring c;//initialise instance c
	
	c = pattern;// "=" operator overloading
	cout<<"after c=pattern c is.."<<endl;
	c.printstring();

	cout<<"after c= data+pattern,  c is..."<<endl;
	c = data+pattern;//"+"operator overloading
	c.printstring();

	c.toUpper();//testing toupper method
	cout<<"c.toupper..."<<endl;
	c.printstring();

	c.toLower();//testing tolower method
	cout<<"c.tolower..."<<endl;
	c.printstring();


	return 0;
}
