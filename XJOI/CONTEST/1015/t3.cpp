/*
 * XJOI CONTEST 1015
 * T3 - 初等数论 (unac)
 * 181017 By SkyWT
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

const int maxn=505;
int n,a[maxn];
vector <int> prime;

inline int Abs(int x){
	return x<0?-x:x;
}

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

inline void make_prime(){
	const int maxnum=1000000;
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
	for (int i=1;i<=n;i++) a[i]=1;
	make_prime();
	srand(517666);
	for (int i=0;i<3000000;i++){
		int nowx=rand()%n+1,nowy=rand()%n+1;
		if (Abs(nowx-nowy)<=1) continue;
		if (gcd(a[nowx],a[nowy])!=1) continue;
		for (int j=0;j<prime.size();j++) if (gcd(a[nowx]*prime[j],a[nowy]*prime[j])!=1){
			bool flg=false;
			if (nowx>1 && a[nowx-1]%prime[j]==0) flg=true;
			if (nowx<n && a[nowx+1]%prime[j]==0) flg=true;
			if (nowy>1 && a[nowy-1]%prime[j]==0) flg=true;
			if (nowy<n && a[nowy+1]%prime[j]==0) flg=true;
			if (flg) continue;
			if (a[nowx]%prime[j]) a[nowx]*=prime[j];
			if (a[nowy]%prime[j]) a[nowy]*=prime[j];
			break;
		}
		if (gcd(a[nowx],a[nowy])==1) printf("fuck\n");
	}
	for (int i=1;i<=n;i++) printf("%lld ",a[i]);
	printf("\n");
	return 0;
}