#include <bits/stdc++.h>

using namespace std;

int Max_sum(int arr[],int n){
	int Max[n];
	Max[0]=arr[0];

	for(int i=1;i<n;i++){
		Max[i]=max(Max[i-1]+arr[i],arr[i]);
	}	
	int m=Max[0];
	for(int j=1;j<n;j++){
		if(Max[j]>=m){
			m=Max[j];
		}
	}
	return m;
}

int main(int argc, char const *argv[])
{
	int arr[6]={-2,-4,4,3,2,-6};
	cout<<Max_sum(arr,6)<<endl;
	return 0;
}