#include <iostream>
#include <algorithm>

using namespace std;

//Finds the length of longest subsequence in the given sequence............
int longest_subseq_len(int arr[],int n){
	
	int L[n];
	L[0]=1;
	for(int i=1;i<n;i++){
		int q=0;
		for(int j=0;j<i;j++){
			if(arr[j]>arr[i])
				continue;
			q=max(q,L[j]);
		}
		L[i]=q+1;
	}

	int mx = L[0];
	for(int i=0;i<n;i++){
		if(mx<L[i])
			mx=L[i];
	}
	return mx;
}

// Driver function..........

int main(int argc, char const *argv[])
{
	int seq[]={7,2,8,1,3,4,10,6,9,5};
	int len = sizeof(seq)/sizeof(int);
	cout<<longest_subseq_len(seq,len)<<endl;
	return 0;
}