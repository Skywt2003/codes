#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2005;
const int tt=1e9+7;

int n,q;
int a[maxn];
int f[maxn][10],s[maxn][10];
int fac[maxn];

void build_fac(){
	fac[0]=1;
	for (int i=1;i<=6;i++) fac[i]=fac[i-1]*i%tt;
}

void build_stelin(){
	
}

void build_dp(int x,int y){
	memset(f,0,sizeof(f));
}

int count_answer(int x,int y,int k){
	int ans=0;
	for (int i=k;i<=n;i++){
		
	}
}

signed main(){
	freopen("sendpoints.in","r",stdin);
	freopen("sendpoints.out","w",stdout);

	n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read();

	if (n==1 && q==1){
		int opt=read(),x=read(),y=read(),k=read();
		if (opt==1) return 0;
		printf("%lld\n",k);
		return 0;
	}

	build_stelin();
	
	while (q--){
		int opt=read();
		if (opt==1){
			int x=read(),y=read(),k=read();
			for (int i=x;i<=y;i++) a[i]=k;
		} else {
			int x=read(),y=read(),k=read();
			build_dp(x,y);
			printf("%lld\n",count_answer(x,y,k));
		}
	}
	return 0;
}
