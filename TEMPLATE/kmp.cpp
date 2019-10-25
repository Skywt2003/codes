#include<bits/stdc++.h>

using namespace std;
namespace KMP{
	int next[maxn];

	inline void make_next(char *p){
		memset(next,0,sizeof(next));
		int len=strlen(p);
		next[0]=next[1]=0;
		int k=0;
		for (int j=1;j<len;j++){
			while (k && p[j]!=p[k]) k=next[k];
			if (p[j]==p[k]) next[j+1]=++k; else next[j+1]=0;
		}
	}

	inline vector<int> query(char *s,char *p){
		vector<int> ret;ret.clear();
		int k=0;
		int n=strlen(s),m=strlen(p);
		for (int j=0;j<n;j++){
			while (k && s[j]!=p[k]) k=next[k];
			if (s[j]==p[k]) k++;
			if (k==m) ret.push_back(j-m+2);
		}
		return ret;
	}
};