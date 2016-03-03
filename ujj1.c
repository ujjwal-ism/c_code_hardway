#include<stdio.h>

#include<stdlib.h>
#include<string.h>


struct Person {
    char *name;
    int age;
    int height;
    int weight;
};
struct Ujjwal {
    char nam;
    int i;
};
   

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

struct Person New_one(char *name, int age, int height, int weight)
{
    struct Person who ;
   

    who.name = strdup(name);
    who.age = age;
    who.height = height;
    who.weight = weight;

    return who;
}
 int main(int argc, char const *argv[])
{
	char *name="Ujjwal";

	struct Person p1 = New_one(name,16,2,4);

	struct Person *p2 = Person_create(name,16,2,4);
	struct Ujjwal p3 ;
	printf("%ld\n",sizeof(p3) );
	

	printf("%s\n",p1.name );
	printf("%s\n",p2->name );

	return 0;
}