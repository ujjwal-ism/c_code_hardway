#include <bits/stdc++.h>

using namespace std;
vector<int> sol;

void computeLPS(char *pat,int m,int *lps){
	int len = 0;

	lps[0] = 0;

	int i = 1;
	while(i < m){
			if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len != 0)
				len = lps[len-1];
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char *pat,char *txt){
	int n = strlen(txt);
	int m = strlen(pat);

	int lps[m];

	computeLPS(pat,m,lps);

	int i = 0; // index for txt
	int j = 0; // index for pat

	while(i < n){
		if(pat[j] == txt[i]){
			i++;
			j++;
		}

		if(j == m){
			sol.push_back(i-j);
		}

		if(i < n && pat[j] != txt[i]){
			if(j != 0)
				j = lps[j-1];
			else
				i += 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	char *txt = "abbabbsdadabbasdsabba";
	char *pat = "abba";

	KMPSearch(pat,txt);

	for(int i = 0;i<sol.size();i++)
		cout<<sol[i]<<" ";
	cout<<endl;

	return 0;
}