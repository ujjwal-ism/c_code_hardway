#include <bits/stdc++.h>

using namespace std;

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[],int lo,int hi){
	int pivot = arr[hi];
	int i = lo - 1;

	for(int j = lo;j < hi; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1],&arr[hi]);

	return i+1;
}

void quicksort(int arr[],int lo,int hi){
	if(lo < hi){
		int pi = partition(arr,lo,hi);

		quicksort(arr,lo,pi-1);
		quicksort(arr,pi+1,hi);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {5,3,7,2,9,6,9,4,5};
	int hi = sizeof(arr)/sizeof(int);

	quicksort(arr,0,hi-1);

	for(int i=0;i<hi;i++)
		cout<<arr[i]<<" ";

	cout<<endl;
	return 0;
}