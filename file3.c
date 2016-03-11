//Receives strings from keyboard and write them to a file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *ft;
	char s[80];

	ft = fopen("ujjwal.txt","w");
    if(ft==NULL)
    {
    	printf("Cannot open file\n");
    	exit(1);
    }
    printf("Enter a few lines of text :\n" );

    while(1){
        gets(s);
        
        if(strlen(s)==0)
            break;

    	fputs(s,ft);
    	fputs("\n",ft);
    }
    
   fclose(ft);
	return 0;
}