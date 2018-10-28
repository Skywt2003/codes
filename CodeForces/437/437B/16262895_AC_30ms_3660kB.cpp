/*
 * Vjudge CONTEST 259101
 * CodeForces 437B The Child and Set
 * 181004 By SkyWT
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

const int maxn=131072+10;
int sum,limit;
vector<int> hsh[maxn];
vector<int> ans;

inline int lowbit(int x){
	return x&(-x);
}

signed main(){
	sum=read();limit=read();
	for (int i=1;i<=limit;i++) hsh[lowbit(i)].push_back(i);

	int cnt=0;
	for (int i=17;i>=0;i--){
		cnt=cnt*2+(bool)(sum&(1<<i));
		for (int j=0;j<min(cnt,(int)hsh[1<<i].size());j++) ans.push_back(hsh[1<<i][j]);
		if (cnt>=hsh[1<<i].size()) cnt-=hsh[1<<i].size(); else cnt=0;
	}

	if (cnt) printf("-1\n"); else{
		printf("%lld\n",(int)ans.size());
		for (int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}