#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
// #define int long long

using namespace std;

const int ha=19260817;
const int maxn=666666+10;
int n,a[maxn];
int ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	freopen("everytime.in","r",stdin);
	freopen("everytime.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) if (a[i]==a[j])
			for (int k=i+1;k<=n;k++) if (a[i]!=a[k])
				for (int t=k+1;t<=n;t++) if (a[k]==a[t])
					ans+=((j>k && j<t && i<k)),ans=ans%ha;
	printf("%d\n",ans);
	return 0;
}
