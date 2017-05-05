#include <bits/stdc++.h>

using namespace std;

void merge(int arr[],int lo,int mid,int hi){
	int i,j,k;
	int n1 = mid - lo + 1;
	int n2 = hi - mid;

	int L[n1],R[n2];

	for(i = 0;i < n1; i++)
		L[i] = arr[lo + i];

	for(j = 0;j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0; j = 0; k = lo;

	while(i < n1 && j < n2){
		if(L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	while(i < n1)
		arr[k++] = L[i++];

	while(j < n2)
		arr[k++] = R[j++];
}

void mergesort(int arr[],int lo,int hi){
	if(lo < hi){
		int mid = lo + (hi - lo)/2;

		mergesort(arr,lo,mid);
		mergesort(arr,mid+1,hi);
		merge(arr,lo,mid,hi);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {6,3,7,2,79,2,3,0,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	mergesort(arr,0,n-1);

	for(int i = 0;i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}