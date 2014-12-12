#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int j,i,n,k;
	char* tmp=NULL;
	char res[10][10];
	char a[]="helloklo";
	char b[]="lo";
	char* r = NULL;
	tmp=a;
	n=strlen(b);
	for(i=0; a!=NULL;i++){
		printf("%s..come again\n",tmp);
		if(	(r = strstr(a,b))!=NULL){
			k = r-a;//r-tmp;
			strncpy(res[i],a,k);
			res[i][k]=0;
			strcpy(a, r+n);
			printf("%s...%ld--%s-->a is %s,-->b is %s\n",tmp,(r-a),r,a,b);

		}
		else break;
	}
	for(j=0; j<i;j++ ){
		printf("this is res...%s\n",res[j]);
	}

	return 0;
}



/*	int msplit(char *x,mystring result[10]){
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
			//	cout<<"delimeter is..."<<x<<endl;
			//	cout<< "token is..."<<token<<endl;
			}

			return i;

		}*/


