//Write records in a file using structure

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(int argc, char const *argv[])
{
	FILE *fs;
	char another='Y';

	struct emp{

		char name[50];
		int age;
		int salary;
	}e;
    
    fs=fopen("Employee.dat","w");
    if(fs==NULL)
    {
       printf("Cannot open file\n");
       exit(1);
    }

    while(another=='Y'){
    	printf("\nEnter name, age and salary :");
    	scanf("%s %d %d",e.name,&e.age,&e.salary);

    	fprintf(fs, "%s %d %d\n",e.name,e.age,e.salary );
        __fpurge(stdin);

    	printf("Add another record (Y,N)\n");
        scanf("%c",&another);
        
    }
    fclose(fs);

	return 0;
}