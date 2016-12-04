// A Program to find the maximum sub-array using divide and conquer.........

#include <bits/stdc++.h>

using namespace std;

int cross_over_sum(int A[],int low,int high){
	
	if(low==high)
		return A[low];

	int mid = (low+high)/2;

	int left = cross_over_sum(A, low, mid);
	int right = cross_over_sum(A, mid +1 , high);

    int left_sum = -999999999;
    int sum = 0;

	for(int i=mid;i>=low;i--){
		sum = sum + A[i];
		if(sum > left_sum){
			left_sum = sum;

		}
	}
	int right_sum = -999999999;
	 sum = 0;

	for(int i=mid+1;i<=high;i++){
		sum = sum + A[i];
		if(sum > right_sum){
			right_sum = sum;

		}
	}
    int mid_sum =left_sum + right_sum;

    return std::max({left, right, mid_sum});
}

//Driver function.......................

int main(int argc, char const *argv[])
{
	int arr[6]={-2,-4,4,3,2,-6};
	cout<<cross_over_sum(arr,0,5)<<endl;
	return 0;
}   