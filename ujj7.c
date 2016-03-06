//Function similar to strcmp............

#include <stdio.h>
#include <string.h>
int xstrcmp(char *,char *);

int main(int argc, char const *argv[])
{
	char source[51],target[101];
	int yuup;

	printf("Enter a string.(not more than 50 characters)\n");
	gets(source);
	printf("Again enter a string.(not more than 50 characters)\n");
    gets(target);

    if(strlen(source)!=strlen(target)){
    	printf("The two strings are totally different:\n");}
else{
    yuup=xstrcmp(target,source);
    if(yuup==0)
    	printf("The two strings are different:\n");
    else if(yuup==1)
        printf("The two strings are SAME......KUDOS\n");

}
return 0;
}

int xstrcmp(char *q,char *p){
   while(*q!='\0'){
   	if(*q==*p){
   		p++;
   		q++;
   		continue ;
   	}
   	else{
   		return 0;
   	}
   }
return 1;
}
