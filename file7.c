// A menu-driven program for elementary database management.

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

//void gotoxy(short int col,short int row);.........This isn't working.

int main(int argc, char const *argv[])
{
	FILE *fp,*ft;
	char another='Y',choice;

	struct emp{
		char name[40];
		int age;
		float bs;
	}e;

    char emp_name[40];
    long int recsize;

    fp=fopen("EMP.DAT","rb+");

    if(fp==NULL){
    	fp=fopen("EMP.DAT","wb+");

    	if(fp==NULL){
    		printf("Cannot open file.\n");
    		exit(1);
    	}
    }

    recsize=sizeof(e);

    while(another=='Y'){
          

          //gotoxy(30,10);
          printf("1. Add Records\n");
          //gotoxy(30,12);
          printf("2. List Records\n");
          //gotoxy(30,14);
          printf("3. Modify Records \n");
          //gotoxy(30,16);
          printf("4. Delete Records\n");
          //gotoxy(30,18);
          printf("0. Exit\n");
          //gotoxy(30,20);
          printf("Your Choice\n");

          __fpurge(stdin);

          scanf("%c",&choice);

          switch(choice){

          	      case '1':
          	        fseek(fp,0,SEEK_END);

          	        another='Y';

          	        while(another=='Y'){
          	        	printf("Enter name ,age and basic salary.\n");
          	        	scanf("%s %d %f",e.name,&e.age,&e.bs);
          	        	fwrite(&e,recsize,1,fp);

                      printf("\n");
          	        	printf("Want to add another Record(Y/N)\n");
          	        	__fpurge(stdin);
          	        	scanf("%c",&another);

          	        }
          	        break;

          	      case '2':

          	          rewind(fp);

          	          while(fread(&e,recsize,1,fp)==1)
          	             printf("%s %d %f\n",e.name,e.age,e.bs );

          	             break;

          	      case '3':

          	        another='Y';
          	        while(another=='Y'){
          	        	printf("Enter the name of employee to be Modified.\n");
          	        	scanf("%s",emp_name);

          	        	rewind(fp);
          	        	while(fread(&e,recsize,1,fp)==1){
          	        		if(strcmp(e.name,emp_name)==0){
          	        			printf("Enter new name ,age and basic salary.\n");
          	        			scanf("%s %d %f",e.name,&e.age,&e.bs);
          	        			fseek(fp,-recsize,SEEK_CUR);
          	        			fwrite(&e,recsize,1,fp);
          	        			break; 	
          	        		}
          	        	}
                      printf("\n");
          	        	printf("Modify another Record(Y/N)\n");
          	        	__fpurge(stdin);
          	        	scanf("%c",&another);
          	        }  
          	        break;

          	      case '4':
          	        another='Y';
          	        while(another=='Y'){
          	        	printf("Enter name of the employee to delete.\n");
          	        	scanf("%s",emp_name);

          	        	ft=fopen("TEMP.DAT","wb");

          	        	rewind(fp);
          	        	while(fread(&e,recsize,1,fp)==1){
          	        		if(strcmp(e.name,emp_name)!=0)
          	        			fwrite(&e,recsize,1,ft);
          	        	}
          	        	fclose(fp);
          	        	fclose(ft);
          	        	remove("EMP.DAT");
          	        	rename("TEMP.DAT","EMP.DAT");

          	        	fp=fopen("EMP.DAT","rb+");

                      printf("\n");
          	        	printf("Delete another Record(Y/N)\n");
          	        	__fpurge(stdin);
          	        	scanf("%c",&another);
          	        }
          	        break;

          	      case '0':
          	          fclose(fp);
          	          exit(0);
          }
          printf("\n");
          printf("Want to anything more(Y/N)\n");
          __fpurge(stdin);
          scanf("%c",&another);

    }
	return 0;
}

/*void gotoxy(short int col,short int row){
	HANDLE h Stdout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position={col,row};
	SetConsoleCursorPosition(hStdout,position);
}*/