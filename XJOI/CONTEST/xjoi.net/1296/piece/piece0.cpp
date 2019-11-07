#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5,maxd=15;

int n,k,a[maxn];

int get_len(int x){
	int ret=0;
	while (x) x/=10,ret++;
	return ret;
}

int qsm(int a,int b){
	int ret=1,w=a%k;
	while (b){
		if (b&1) ret=ret*w%k;
		w=w*w%k; b>>=1;
	}
	return ret;
}

signed main(){
	n=read(); k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (i!=j){
			int now=(a[i]%k*qsm(10,get_len(a[j]))%k+a[j]%k)%k;
			if (now) ans++;
		}
	
	printf("%lld\n",ans);
	return 0;
}
