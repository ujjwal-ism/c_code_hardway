#include <stdio.h>

int main(int argc,char *argv[]){

	//Create 2 arrays we are interested in .
	int ages[]={12,45,34,56,67};
	char *names[]={"Alan","chris","kadwa","kancha","Shubham"};

	//find the size of ages.....elegant way.
	int count =sizeof(ages)/sizeof(int);
	int i=0;

	for(i=0;i<count;i++){
		printf("%s is %d years old.\n",names[i],ages[i] );
	}

	printf("------\n");

	//set the pointers to the start of the array.
	int *cur_ages=ages;
	char **cur_names=names;

	//second way of using pointers
	for(i=0;i<count;i++){
		printf("%s is %d years old.\n",*(cur_names+i),*(cur_ages+i) );
	}

	printf("------\n");

	//third way of using pointers.
	for (int i = 0; i < count; ++i)
	{
		printf("%s is %d years old.\n",cur_names[i],cur_ages[i] );
	}

	printf("------\n");

	//fourth way of using pointers....complex....doesn't get it yet.
	for(cur_names = names, cur_ages = ages;
            (cur_ages - ages) < count;
            cur_names++, cur_ages++)
    {
        printf("%s lived %d years so far.\n",
                *cur_names, *cur_ages);
    }
    printf("%s\n", );

    return 0;
}