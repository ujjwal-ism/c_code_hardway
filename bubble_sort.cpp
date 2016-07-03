// The worst sorting algorithm........but still it works

void bubble_sort(std::vector<int>& v){
	bool sorted = false;
	int last = v.size()-1;

	while(!sorted){
		sorted=true;
		for (int i = 0; i < last; ++i)
		{
			if(v[i+1]<v[i]){
				swap(v[i],v[i+1]);
				sorted=false;
			}
		}
		last--;
	}
}