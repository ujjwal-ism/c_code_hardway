#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort(std::vector<int>& v){
	int last = v.size()-1;

	for (int i = 0; i < last; ++i)
	{
		int k = pos_min(v,i,last);
		swap(v[k],v[i]);
	}
}

int pos_min(const vector<int>& v,int left,int right){
	int pos = left;

	for (int i = left+1; i <= right; ++i)
	{
		if(v[i]<v[pos])
			pos=i;
	}
	return pos;
}