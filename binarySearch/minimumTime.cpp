#include <bits/stdc++.h>

using namespace std;

bool isSafe(int arr[],int tim,int k,int n){
	int curr_emp = 1;
	int curr_time = 0;

	for(int i=0;i<n;i++){
		if(curr_time + arr[i] > tim){
			curr_time = 0;
			curr_emp++;
		}
		curr_time += arr[i];
	}
	if(curr_emp > k)
		return false;
	else
		return true;
}

int Time(int arr[],int k,int T,int n){
	int low = 0,end=0;
	for(int i=0;i<n;i++)
		end += arr[i];

	int ans = end;

	while(low <= end){
		int mid = low + (end - low)/2;
		if(isSafe(arr,mid,k,n)){
			ans = min(ans,mid);
			end = mid - 1;
		}
		else
			low = mid + 1;
	}

	return (ans*T);
}

int main(int argc, char const *argv[])
{
	int arr[] = {10,7,8,12,6,8};
	int k = 4,T = 5;
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<Time(arr,k,T,n)<<endl;

	return 0;
}