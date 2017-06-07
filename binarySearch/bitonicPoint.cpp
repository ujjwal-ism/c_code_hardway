#include <bits/stdc++.h>

using namespace std;

int bitonicIndex(int arr[],int low,int high){
	if(high < low) return -1;

	int mid = low + (high - low)/2;

	if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid+1])
		return mid;

	else if(arr[mid] > arr[mid - 1])
		return bitonicIndex(arr,mid+1,high);
	else
		return bitonicIndex(arr,low,mid-1);
}

int main(int argc, char const *argv[])
{
	int arr[] = {3,4,6,11,11,9,8,6,4,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<bitonicIndex(arr,0,n-1)<<endl;
	return 0;
}