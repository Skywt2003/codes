#include<cstdio>
#include<cstring>
#include<iostream>
// #define int long long
using namespace std;

const int maxn=1e7+5;
int n,m;
int a[maxn];
bool vis[maxn];
double ans=0.0;
double p=0.0;
int sum1=0,n1=0,sum2=0,n2=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	freopen("winner.in","r",stdin);
	freopen("winner.out","w",stdout);
	n=read();m=n2=read();
	for (int i=1;i<=m;i++) a[i]=read(),vis[a[i]]=true,sum2+=a[i];
	for (int i=0;i<n;i++) if (!vis[i]) sum1+=i,n1++;
	p=1.0/n;
	while (p*sum2>1.0e-8){
		ans+=p*sum2;
		sum2=n2*sum1+n1*sum2;
		n2=n2*n1;
		p=p*1.0/n;
	}
	printf("%.6lf\n",ans);
	return 0;
}