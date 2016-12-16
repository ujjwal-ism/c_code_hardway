#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>

using namespace std;

int change_making(int denominations[], int len,int ammount){
	int coins[ammount+1];
	coins[0]=0;
	for(int i=1;i<=ammount;i++){
		int q = INT_MAX;
		for(int j=0; j<= len; j++){
			if((i-denominations[j])<0)
				break;
			q=min(q,coins[i-denominations[j]]+1);
		}
		coins[i]=q;
	}
	return coins[ammount];
}

int main(int argc, char const *argv[])
{
	int change[4]={1,2,3,4};
	cout<<change_making(change, 4, 90)<<endl;
	return 0;
}