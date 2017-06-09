#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;cin>>t;
	int x,y;
	vector<int> q(t);

	for(int i=0;i<t;i++){
		cin>>x>>y;
		q[i] = x*x + y*y;
	}
	sort(q.begin(),q.end());

	cin>>t;
	while(t--){
		cin>>x;
		cout<<upper_bound(q.begin(),q.end(),x*x) - q.begin()<<endl;
	}

	return 0;
}