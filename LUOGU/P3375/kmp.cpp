#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

const int maxn=2000005;

int n,m;
char s[maxn],p[maxn];

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
}

signed main(){
	scanf("%s",s);
	scanf("%s",p);
	n=strlen(s);m=strlen(p);
	KMP::make_next(p);
	vector<int> ans=KMP::query(s,p);
	for (int i=0;i<ans.size();i++) printf("%lld\n",ans[i]);
	for (int i=1;i<=m;i++) printf("%lld ",KMP::next[i]);
	printf("\n");
	return 0;
}