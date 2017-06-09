#include <bits/stdc++.h>

using namespace std;

int search(int preSum[],int k,int n){
	int ans  = -1;

	int low = 1,high = n;
	while(low <= high){
		int mid = low + (high - low)/2;
		int i;
		for(i = mid;i<=n;i++){
			if(preSum[i] - preSum[i-mid] > k)
				break;
		}

		if(i == n+1){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,10,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int preSum[n+1];
	preSum[0] = 0;

	int k = 14;

	for(int i=1;i<=n;i++)
		preSum[i] = arr[i-1] + preSum[i-1];

	cout<<search(preSum,k,n)<<endl;

	return 0;
}