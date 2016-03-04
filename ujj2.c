#include <stdio.h>

//2-D array and pointers.
int main(){

	int arr[4][2]={1212,34,1342,56,1723,78,1923,57};
    int i,j;

	for(i=0;i<4;i++){
		printf("Adress of 1st element of %d row =%u \t",i,arr[i] );
		printf("value of the element =%d\n",arr[i][0] );
	}
	printf("\n");
	//Print the elements of the array ...unique approach(pointers)
	for(i=0;i<4;i++){
		for(j=0;j<=1;j++){
			printf("Adress of %d row %d column element: %d\t",i,j,arr[i]+j );
		    printf("value of element = %d\n",*(arr[i]+j));

		}
	}//end
	printf("\n");
	//Another approach to print elements:......array of pointers.
    int (*p)[2];
    int *pq;

    for (int i = 0; i < 4; ++i)
     {
     	p=&arr[i];
     	pq=(int *)p;
     	printf("\n");
       for ( int i = 0; i<=1 ; ++i)
       {
       	printf("%d\t",*(pq+i));
       }
     } //end
     printf("\n");
	return 0;
}