#include <bits/stdc++.h>

using namespace std;

int findpivot(int arr[],int low,int high){
	if(high < low) return -1;
	if(high == low) return low;

	int mid = low + (high-low)/2;
	
	if(mid < low && arr[mid] > arr[mid+1]) return mid;
	if(mid > low && arr[mid] < arr[mid-1]) return mid-1;

	if(arr[low] <= arr[mid])
		return findpivot(arr,mid+1,high);
	else
		return findpivot(arr,low,mid-1);
}

int binaryS(int arr[],int low,int high,int key){
	if(high < low) return -1;
	int mid = (low+high)/2;

	if(arr[mid] == key)
		return mid;
	if(arr[mid] < key)
		return binaryS(arr,mid+1,high,key);
	else
		return binaryS(arr,low,mid-1,key);
}

int search(int arr[],int n,int elem){
	int pivot = findpivot(arr,0,n-1);

	if(pivot == -1)
		return binaryS(arr,0,n-1,elem);
	if(arr[pivot] == elem)
		return pivot;
	if(arr[0] <= elem)
		return binaryS(arr,0,pivot-1,elem);
	else
		return binaryS(arr,pivot+1,n-1,elem);
}

int main(int argc, char const *argv[])
{
	int arr[] = {5,6,7,8,9,10,2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int q;cin>>q;

	cout<<search(arr,n,q)<<endl;

	return 0;
}