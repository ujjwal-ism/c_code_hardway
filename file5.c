//Write in a file opened in binary mode using fwrite
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *fs;
	char another='Y';
	struct emp{
		char name[30];
		int age;
		int bs;
	}e;

	fs=fopen("emp.dat","wb");
	if(!fs){
		printf("Cannot open file\n");
		exit(1);
	}
	while(another=='Y'){
        printf("Enter name,age and basic salary of employee\n");
        scanf("%s%d%d",e.name,&e.age,&e.bs);

        fwrite(&e,sizeof(e),1,fs);
        __fpurge(stdin);
        printf("Enter another record (Y/N)\n");
        scanf("%c",&another);
	}
	printf("\n");
	fclose(fs);
	return 0;
}