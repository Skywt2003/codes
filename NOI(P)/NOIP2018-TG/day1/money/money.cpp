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

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while (T--){
		n=ans=read();allv=0;
		for (int i=1;i<=n;i++) a[i]=read(),allv=max(allv,a[i]);
		for (int k=1;k<=n;k++){
			memset(f,0,sizeof(f));
			f[0]=true;
			for (int i=1;i<=n;i++) if (i!=k){
				for (int j=a[i];j<=a[k];j++) f[j]|=f[j-a[i]];
			}
			if (f[a[k]]) ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
