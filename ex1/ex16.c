#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

struct Person 
{
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_Create(char *name,int age,int height,int weight){

	struct Person *who =malloc(sizeof(struct Person));
	assert(who!=NULL);

	who->name=strdup(name);
	who->age=age;
	who->height=height;
	who->weight=weight;

	return who;
}

void Person_destroy(struct Person *who){

	assert(who!=NULL);

	free (who->name);
	free (who);
}

void Person_print(struct Person *who){

	printf("Name : %s\n",who->name );
	printf("\t Age : %d\n",who->age );
	printf("\t Height : %d\n",who->height );
	printf("\t Weight : %d\n",who->weight );
}

int main(int argc, char const *argv[])
{
	// make two people structures

	struct Person *ujj=Person_Create("Ujjwal kumar",19,163,60);
	struct Person *abhi=Person_Create("Abhishek kumar pandey",20,175,58);

	//print them out and where they are in memory
    printf("ujj is at a memory location : %p\n",ujj );
    Person_print(ujj);

    printf("abhi is at a memory location : %p\n",abhi );
    Person_print(abhi);

    //destroy both of them :----
    Person_destroy(ujj);
    Person_destroy(abhi);

	return 0;
}