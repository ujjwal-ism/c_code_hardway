//Function similar to strlen.......

#include <stdio.h>
int xstrlen(char *q);

int main(int argc, char const *argv[])
{
	char str[50];
	int len;
	printf("Enter a string.(not more than 50 characters)\n");
    gets(str);

    len = xstrlen(str);
    puts("No. of characters in :");
    puts(str);
    printf("%d\n",len );
	return 0;
}

int xstrlen(char *q){
	int length=0;

	while(*q!='\0'){
        
        length++;
        q++;
	}
	return(length); 
}