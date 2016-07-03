// Better algorithm than selection sort but far from best

void insertion_sort(std::vector<int>& v){
	for (int i = 1; i < v.size(); ++i)
	{
		int x = v[i];
		int j=i;

		while(j>0 && v[j-1]>x){
			v[j]=v[j-1];
			j--;
		}
		v[j]=x;
	}
}