#include<stdio.h>

int main(int argc, char *argv[]) {

	puts("Hello World");
	printf("%d\n",argc);
	int i = 0;
	for(i =0 ; i< argc; i++) {
		printf("%s\n",argv[i]);
	}
	
	return 0;
}
