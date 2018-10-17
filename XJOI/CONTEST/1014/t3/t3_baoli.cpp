/*
 * XJOI CONTEST 1014
 * T3 - ABC 难题（暴力）
 * 181006 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3005;
int n,s[maxn],a[maxn];
int cnt0[maxn],cnt1[maxn];
int ans=0;
map<int,int> num;

inline void build(int step){
	if (step==n){
		for (int i=1;i<=n;i++) cnt0[i]=cnt0[i-1]+(a[i]==0);
		for (int i=n;i>=1;i--) cnt1[i]=cnt1[i+1]+(a[i]==2);
		for (int i=1;i<=n;i++) if (a[i]==1 && cnt0[i] && cnt1[i]){
			ans++;
			for (int i=1;i<=n;i++) putchar((a[i]==0)?'A':((a[i]==1)?'B':'C'));
			printf("\n");
			return;
		}
		return;
	}
	if (num[s[step+1]]!=-1) {a[step+1]=num[s[step+1]];build(step+1);} else{
		for (int i=0;i<3;i++) {a[step+1]=num[s[step+1]]=i;build(step+1);}
		num[s[step+1]]=-1;
	}
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) s[i]=read(),num[s[i]]=-1;
	build(0);
	printf("%lld\n",ans);
	return 0;
}