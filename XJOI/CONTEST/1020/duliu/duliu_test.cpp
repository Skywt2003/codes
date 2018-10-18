#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

const int maxn=105;
const int max_deep=6;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;
int s[maxn],t[maxn];
int ans=1<<30;
vector<pair <int,int> > ansv;

inline void search(int step,vector<pair <int,int> > opt){
	printf("step=%lld\n",step);
	if (step>max_deep) return;
	bool flg=true;
	for (int i=1;i<=n;i++){
		if (s[i]!=t[i]) {flg=false;break;}
	}
	if (flg){
		if (step<ans){
			ans=step;
			ansv=opt;
		}
		return;
	}

	int xor_sum=0;
	for (int i=1;i<=n;i++) xor_sum^=s[i];
	for (int i=1;i<=n;i++){
		vector< pair<int,int> > now;
		now=opt;
		int tmp=s[i];
		now.push_back(make_pair(s[i],xor_sum));
		s[i]=xor_sum;
		search(step+1,now);
		s[i]=tmp;
	}
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) s[i]=read();
	for (int i=1;i<=n;i++) t[i]=read();
	vector< pair<int,int> > st;
	st.clear();
	search(0,st);
	if (ans==1<<30) printf("-1\n"); else{
		printf("%lld\n",ans);
		for (int i=0;i<ansv.size();i++) printf("%lld -> %lld\n",ansv[i].first,ansv[i].second);
		printf("\n");
	}
	return 0;
}