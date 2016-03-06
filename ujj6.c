//Function similar to strcat............

#include <stdio.h>
#include <string.h>
void xstrcat(char *,char *,int);

int main(int argc, char const *argv[])
{
	char source[51],target[101];
	int len;

	printf("Enter a string.(not more than 50 characters)\n");
	gets(source);
	printf("Again enter a string.(not more than 50 characters)\n");
    gets(target);

    len=strlen(target);
    xstrcat(target,source,len);

    printf("After catenation:----\n");
    puts(target);

	return 0;
}

void xstrcat(char *p,char *q,int len){

	p=p+len;
	*p=' ';
	p++;

	while(*q!='\0'){
		*p=*q;
		p++;
		q++;
	}
	*p='\0';
}