#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105,maxv=25005;

int T;
int n,a[maxn],ans,allv;
bool f[maxv];

void init(){
	memset(f,0,sizeof(f));
}

signed main(){
	T=read();
	while (T--){
		init();

		n=ans=read();
		for (int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+1+n); allv=a[n];
		f[0]=true;
		for (int i=1;i<=n;i++){
			if (f[a[i]]) ans--;
			f[a[i]]=true;
			for (int j=a[i];j<=allv;j++) f[j]|=f[j-a[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}