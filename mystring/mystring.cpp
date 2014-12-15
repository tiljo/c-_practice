
		mystring::mystring(){//constructor
			if((str_ptr = (char*)malloc(2*sizeof(char)))==NULL){
				perror("malloc");
				exit(1);
			}
			strcpy(str_ptr,"d");
		}

		mystring::~mystring(){//destructor
			free(str_ptr);
		}

		mystring::mystring(const mystring &o){//custom cunstructor
			int size = strlen(o.str_ptr);
			if((str_ptr = (char*)malloc((size+1)*sizeof(char)))==NULL){
				perror("malloc");
				exit(1);
			}
			strcpy(str_ptr,o.str_ptr);
		}

		int mystring::search(const mystring& x){//method to search for pattern
			char* r=NULL;
			if((r=strstr(str_ptr,x.str_ptr))!=NULL){
				return r-str_ptr;
			}
			else{
				cout<< "SEARCH COMPLETED"<< endl;
				return -1;
			}
		}

		
		void mystring::stringcopy(char* x){
			int size = strlen(x);
			assert(size>0);
			assert(str_ptr!=NULL);
			char* tmp = NULL;
			if(( tmp = (char*)realloc(str_ptr,(size+1)*sizeof(char)))==NULL){//error checking for realloc
				perror("realloc");
				free(str_ptr);
				exit(1);
			}
			str_ptr = tmp;
			strcpy(str_ptr,x);

		}

		int mystring::getLength(){
			return(strlen(str_ptr));
		}

		void mystring::toLower(){
			unsigned int i;
			for(i=0; i<strlen(str_ptr);i++){
				str_ptr[i] = tolower(str_ptr[i]);
			}
			str_ptr[i]=0;
		}


		void mystring::toUpper(){
			unsigned int i;
			for(i=0; i<strlen(str_ptr);i++){
				str_ptr[i] = toupper(str_ptr[i]);
			}
			str_ptr[i]=0;
		}

		int mystring::msplit(char *x,mystring* result){
			int i=0,n,k;
			n = strlen(str_ptr);
			char *a=NULL;//a is a temporay char pointer , used to protect original str_ptr
			if((a = (char*)malloc(n*sizeof(char)))==NULL){
				perror("malloc");
				exit(1);
			}

			strcpy(a,str_ptr);

			char* r = NULL;
			n=strlen(x);
			while(strcmp(a,"")!=0){
				if(	(r = strstr(a,x))!=NULL){
					k = r-a;
					char* res=NULL;//"res" temporarly stores the splitted word
					if((res = (char*)malloc((k+1)*sizeof(char)))==NULL){
						perror("malloc");
						exit(1);
					}
					strncpy(res,a,k);
					res[k]=0;
					if(res[0]!=0){

					result[i].stringcopy(res);
					i++;
					}
					strcpy(a, r+n);//updating a , after splitting

					free(res);
				}
				else{//when no match found, last word stored as instance
						result[i].stringcopy(a);
						i++;
				   		break;
				}
			}
			free(a);
			return i;
		}


		int mystring::countsplit(char *x){//this method calculate no.of instance to be formed after splitting
			int i=0,n;
			n = strlen(str_ptr);
			char* a = NULL;
			if(( a = (char*)malloc(n*sizeof(char)))==NULL){//str_ptr stored into temporary variable "a"
				perror("malloc");
				exit(1);
			}
			strcpy(a,str_ptr);
			char* r = NULL;
			n=strlen(x);
			while(a[0]!=0){
				if(	(r = strstr(a,x))!=NULL){
					if(a!=r)	i++;//ia a==r neglect the unsplitted word
				strcpy(a, r+n);
				}
				else{//count the last word
						i++;
				   		break;
				}
			}
			free(a);
			return i;
		}


		void mystring::printstring(){
			cout<< str_ptr<<endl;
			cout<<endl;
		}

		void mystring::stringcat(char* x){
			int parentsize = strlen(str_ptr);
			int catsize = strlen(x);
			if((str_ptr = (char*)realloc(str_ptr,parentsize + catsize+2))==NULL){
				perror("realloc");
				exit(1);
			}
			strcat(str_ptr,x);
		}

		void mystring::operator=(const mystring &x){
			if((str_ptr = (char*)realloc(str_ptr,(strlen(x.str_ptr)+1)))==NULL){
				perror("realloc");
				exit(1);
			}
			strcpy(str_ptr,x.str_ptr);
		}

		mystring mystring::operator+(const mystring &x){
			mystring temp;
			temp.stringcopy(this->str_ptr);
			temp.stringcat(x.str_ptr);
			return temp;
		}

		


