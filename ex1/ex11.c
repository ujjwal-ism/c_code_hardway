#include<stdio.h>

int main(int argc,char *argv[]){

	//print the argument taken
    int i=0;

	while(i<argc){
		printf("arg %d: %s\n",i,argv[i] );
       i++;
	}

    //creating our own strings

	char *states[]={
     "California","texas","Florida","Buffalo"
	};
	int num_states=4;
	i=0; //watch for this

	while(i<num_states){
		printf("State %d: %s\n",i,states[i] );
		i++;
	}
	
	return 0;
}