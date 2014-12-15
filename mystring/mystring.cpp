
		mystring::mystring(){
			if((str_ptr = (char*)malloc(2*sizeof(char)))==NULL){
				perror("malloc");
				exit(1);
			}
		//	printf("malloced...%p\n",str_ptr);
			strcpy(str_ptr,"d");
		}

		mystring::~mystring(){
		//	printf("deleting..%p\n",str_ptr);
			free(str_ptr);
		}

		mystring::mystring(const mystring &o){
			int size = strlen(o.str_ptr);
			if((str_ptr = (char*)malloc((size+1)*sizeof(char)))==NULL){
				perror("malloc");
				exit(1);
			}
		//	printf("malloced....%p\n",str_ptr);
			strcpy(str_ptr,o.str_ptr);
		}

		int mystring::search(const mystring& x){
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
			if(( tmp = (char*)realloc(str_ptr,(size+1)*sizeof(char)))==NULL){
				perror("realloc");
				free(str_ptr);
				exit(1);
			}
			str_ptr = tmp;
		//	printf("in strcp: reallocd.....%p	\n",str_ptr);
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
			char *a=NULL;
			if((a = (char*)malloc(n*sizeof(char)))==NULL){
				perror("malloc");
				exit(1);
			}

		//	printf("malloced...in msplt for a,...%p\n",a);
			strcpy(a,str_ptr);

			char* r = NULL;
			n=strlen(x);
			while(strcmp(a,"")!=0){
				if(	(r = strstr(a,x))!=NULL){
					k = r-a;
					char* res=NULL;
					if((res = (char*)malloc((k+1)*sizeof(char)))==NULL){
						perror("malloc");
						exit(1);
					}
		//			printf("malloced for res,...%p\n",res);
					strncpy(res,a,k);
					res[k]=0;
					if(res[0]!=0){

					result[i].stringcopy(res);
					i++;
					}
					strcpy(a, r+n);

		//			printf("freeing res..,...%p\n",res);
					free(res);
				}
				else{
						result[i].stringcopy(a);
						i++;
				   		break;
				}

			}

		//	printf("freeing  a,...%p\n",a);
			free(a);

			return i;
		}


		int mystring::countsplit(char *x){
			int i=0,n;
			n = strlen(str_ptr);
			char* a = NULL;
			if(( a = (char*)malloc(n*sizeof(char)))==NULL){
				perror("malloc");
				exit(1);
			}

		//	printf("malloc in countsplit  a,...%p\n",a);

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
			
		//	printf("freeing in cntsplit  a,...%p\n",a);
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

		//	printf("in strcat:  realloc str_ptr,...%p\n",str_ptr);
			strcat(str_ptr,x);
		}

		void mystring::operator=(const mystring &x){
			if((str_ptr = (char*)realloc(str_ptr,(strlen(x.str_ptr)+1)))==NULL){
				perror("realloc");
				exit(1);
			}
		//	printf("realloc str_ptr in =,...%p\n",str_ptr);
			strcpy(str_ptr,x.str_ptr);
		}

		mystring mystring::operator+(const mystring &x){
			mystring temp;
			temp.stringcopy(this->str_ptr);
			temp.stringcat(x.str_ptr);
			return temp;
		}

		


