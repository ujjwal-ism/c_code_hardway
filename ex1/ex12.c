#include<stdio.h>

int main(int argc,char *argv[]){
	//first if statement

	if (argc==1)
	{
	printf("You have only one argument.You suck\n");
	}else if(argc>1 && argc<4){
		printf("Your arguments are:\n");
		for(int i=1;i<3;i++){
			printf("argument %d: %s\n",i,argv[i]);
		}
		printf("\n");
	}
		else{
			printf("You have too many arguments.You suck\n");
		}
	return 0;
}