#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105,maxv=25005;
int T,n,ans,allv,a[maxn];
bool f[maxv];
bool vis[maxn];

int main(){
	T=read();
	while (T--){
		memset(vis,0,sizeof(vis));
		n=ans=read();allv=0;
		for (int i=1;i<=n;i++) a[i]=read(),allv=max(allv,a[i]);
		sort(a+1,a+1+n);
		memset(f,0,sizeof(f));
		f[0]=true;
		for (int i=1;i<=n;i++){
			if (f[a[i]]) ans--;
			for (int j=a[i];j<=allv;j++) f[j]|=f[j-a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
