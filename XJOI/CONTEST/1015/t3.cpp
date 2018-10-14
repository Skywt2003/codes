/*
 * XJOI CONTEST 1015
 * T3 - 初等数论 (unac)
 * 181008 By SkyWT
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

#define write(_) cout<<#_<<" = "<<_<<endl;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;
int n,now=4;
vector <int> a[maxn];
vector <int> prime;
map <int,bool> vis;
map <int,bool> chs;

inline void make_prime(){
	const int maxnum=1000;
	bool vis[maxnum+5];
	memset_clear_tre(vis);
	prime.clear();
	for (int i=2;i<=maxnum;i++){
		if (vis[i]) prime.push_back(i);
		for (int j=0;j<prime.size();j++){
			if (i*prime[j]>maxnum) break;
			vis[i*prime[j]]=false;
			if (i%prime[j]==0) break;
		}
	}
	// write(prime.size());
}

signed main(){
	n=read();
	make_prime();
	a[1].push_back(2);a[1].push_back(5);
	a[2].push_back(3);a[2].push_back(7);
	for (int i=3;i<=n;i++){
		vis.clear();chs.clear();
		for (int k=0;k<a[i-1].size();k++) vis[a[i-1][k]]=true;
		for (int j=1;j<=i-2;j++){
			bool flg=false;
			for (int k=0;k<a[j].size();k++){
				if (vis[a[j][k]]) continue;
				if (chs[a[j][k]]) {flg=true;break;}
			}
			if (flg) continue;
			for (int k=0;k<a[j].size();k++) if (!vis[a[j][k]]){
				a[i].push_back(a[j][k]);
				chs[a[j][k]]=true;
				break;
			}
		}
		a[i].push_back(prime[now++]);
	}
	for (int i=1;i<=n;i++){
		int now=1;
		for (int j=0;j<a[i].size();j++) now=now*a[i][j];
		printf("%lld ",now);
	}
	printf("\n");
	return 0;
}