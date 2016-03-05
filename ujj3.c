//Passing 2 D array to a function ......3 methods

#include <stdio.h>

void show(int q[][2],int,int);
void display(int *q,int,int);
void print(int (*q)[2],int,int);

int main(int argc, char const *argv[])
{
	int arr[4][2]={
		1212,34,
		1334,45,
		1224,67,
		3544,23
	};

	show(arr,4,2);
	display(arr,4,2);
	print(arr,4,2);

return 0;
}
//First Method :---
void show(int q[][2],int row,int col){
	for (int i = 0; i < row; ++i)
	{
	 for (int j = 0; j < col; ++j)
	 {
	 	printf("%d\t",q[i][j] );
	 }
	 printf("\n");
	}
}
 
//Second Method:-----
void display(int *q,int row,int col){
	printf("\n");
	printf("%d\t",q );
    printf("%d\n",*q );
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%d \t",*(q+i*col+j) );
		}
		printf("\n");
	}
}

//Third Method:-----
void print(int (*q)[2],int row,int col){
	printf("\n");
	int *pq;

	for (int i = 0; i < row; ++i)
	{
		pq=q+i;
		for (int j = 0; j < col; ++j)
		{
	      printf("%d\t",*(pq+j) );
		}
		printf("\n");
	}
}