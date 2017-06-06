#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void sieveofErato(vector<int> &primes)	{
	int n = 100000;
	bool p[n+1];
	memset(p,true,sizeof(p));

	for(int i=2;i*i<=n;i++)	{
		if(p[i]==true)	{
			for(int j = i*2;j<=n;j+=i)
				p[j] = false;
		}
	}

	for(int i=2;i<=n;i++){
		if(p[i])
			primes.push_back(i);
	}
}

int sol(int limit,vector<ll> &sum, vector<int> &primes )	{
	int size = -1;
	int prime = -1;

	for(int i=0;primes[i]<=limit;i++)	{
		for(int j=0;j<i;j++)	{
			ll c = sum[i] - sum[j];

			if(c > limit)
				continue;

			if(binary_search(primes.begin(),primes.end(),c))	{
				if(size < i - j + 1){
					size = i-j+1;
					prime = c;
				}
			}
		}
	}

	return prime;
}

int main(int argc, char const *argv[])
{
	vector<int> primes;
	sieveofErato(primes);

	int l = primes.size();
	vector<ll> sum(l+1);

	sum[0] = 0;
	for(int i=1;i<=l;i++)
		sum[i] = sum[i-1] + primes[i-1];

	int n,t;cin>>t;
	while(t--){
		cin>>n;
		cout<<sol(n,sum,primes)<<endl;
	}	

	return 0;
}