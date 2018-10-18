#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

const int maxn=105;
const int max_deep=16;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;
int s[maxn],t[maxn];
int ans=1<<30;
vector<int> p;

inline void search(int step,int lft,int xor_sum){
	if (ans-step<lft) return;
	if (max_deep-step<lft) return;
	if (step>max_deep) return;
	if (step>ans) return;
	bool flg=true;
	for (int i=1;i<=n;i++){
		if (s[i]!=t[i]) {flg=false;break;}
	}
	if (flg){
		ans=min(ans,step);
		return;
	}

	for (int j=0;j<n;j++){
		int i=p[j];
		if (s[i]==t[i]) continue;
		int tmp=s[i];
		s[i]=xor_sum;
		search(step+1,lft-(s[i]==t[i]),tmp);
		s[i]=tmp;
	}
}

inline int Abs(int x){
	return x<0?-x:x;
}

signed main(){
	freopen("duliu.in","r",stdin);
	freopen("duliu.out","w",stdout);
	srand(time(0));
	n=read();int sl=0;
	for (int i=1;i<=n;i++) p.push_back(i);
	random_shuffle(p.begin(),p.end());
	int ssum=0;
	for (int i=1;i<=n;i++) s[i]=read(),ssum^=s[i];
	for (int i=1;i<=n;i++) t[i]=read(),sl+=s[i]!=t[i];
	if (n>10){
		int cnt1=0,cnt2=0;
		for (int i=1;i<=n;i++) cnt1+=(s[i]==1&&t[i]==0),cnt2+=(s[i]==0&&t[i]==1);
		if (Abs(cnt1-cnt2)>1) printf("-1\n"); else printf("%lld\n",cnt1+cnt2);
	}
	search(0,sl,ssum);
	if (ans==1<<30) printf("-1\n"); else{
		printf("%lld\n",ans);
	}
	return 0;
}