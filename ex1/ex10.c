#include<stdio.h>

int main(int argc,char *argv[]){
	int i=0;

	// go through each string in argv

	for(i;i<argc;i++){
		printf("arg %d: %s\n",i,argv[i] );
	}

	// let's make our own array of strings

	char * states[]={
		  "California","Florida","Buffalo","Texas",
	};
	int num_states=4;

	for(i=0;i<num_states;i++){
		printf("State %d: %s\n",i,states[i] );
	}
	printf("%c\n",states[0][0] );//print as a character
	printf("%d\n",states[0] );//print the memory location
	printf("%d\n",&states[0][0] );//same as above
	printf("%d\n",states[0][0] );//print the ascii value in states[0][0]
	

	return 0;
}