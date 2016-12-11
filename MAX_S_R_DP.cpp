#include <bits/stdc++.h>

using namespace std;

int Max[5000];

int Max_Sum(int arr[],int n){
	if(n==0)
		return arr[0];
	else if(Max[n] != -99999)
		return Max[n];
	else{
		Max[n]=max(Max_Sum(arr,n-1)+arr[n],arr[n]);
		return Max[n];
	}
}

int main(int argc, char const *argv[])
{
	fill_n(Max,5000,-99999);
	int arr[6]={-2,-4,4,3,2,-6};
	Max[0]=arr[0];

	Max_Sum(arr,5);
	int m=Max[0];
	for(int i=1;i<6;i++){
		if(Max[i]>m)
			m=Max[i];
	}

	cout<<m<<endl;
	return 0;
}