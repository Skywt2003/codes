#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=1e9+7;

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

const int maxn=1e5+5,N=1e5;

int fac[maxn],inv[maxn];

vector<int> factor[maxn];

void prebuild(){
	fac[0]=1;
	for (int i=1;i<=N;i++)
		fac[i]=fac[i-1]*i%tt,
		inv[i]=qsm(fac[i],tt-2);

	for (int i=2;i<=N;i++)
		for (int j=i;j<=N;j+=i)
			factor[j].push_back(i);
}

int C(int x,int y){
	if (x<y) return 0;
	return fac[x]*inv[y]%tt*inv[x-y]%tt;
}

int f[maxn];
int vis[maxn]; int cnt=0;

int get_answer(int n,int m){
	if (vis[n]==cnt) return f[n];
	if (n==m) return 1;
	if (n<m || m==1) return 0;
	vis[n]=cnt;

	int ans=C(n-1,m-1);
	for (int i=0;i<factor[n].size();i++){
		int now=get_answer(n/factor[n][i],m);
		ans=(ans-now+tt)%tt;
	}
	return f[n]=ans;
}

int q,n,m;

signed main(){
	prebuild();

	q=read();
	while (q--){
		n=read();m=read();
		cnt++;
		printf("%lld\n",get_answer(n,m));
	}
	return 0;
}