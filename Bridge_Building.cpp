#include <iostream>
#include <algorithm>

using namespace std;

int MaxBridges(int Upper[],int n){
	int X[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(Upper[j]==i){
				X[i]=j;
				break;
			}
		}
	}
	int L[n];
	L[0]=1;
	for(int i=1;i<n;i++){
		int q=0;
		for(int j=0;j<i;j++){
			if(X[j]>X[i])
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

int main(int argc, char const *argv[])
{
	int Upper[10]={6,1,7,0,2,3,9,5,8,4};
	cout<<MaxBridges(Upper,10)<<endl;
	return 0;
}