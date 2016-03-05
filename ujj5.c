//Function similar to strcpy.........

#include <stdio.h>
void xstrcpy(char *,char *);

int main(int argc, char const *argv[])
{
	char str[50],tar[50];
	printf("Enter a string.(not more than 50 characters.)\n");
	gets(str);

	xstrcpy(tar,str);

    printf("String entered :\n");
    puts(str);

    printf("String copied :\n");
    puts(tar);

	return 0;
}

void xstrcpy(char *q,char *p){

	while(*p!='\0'){
		*q=*p;
		q++;
		p++;
	}
}