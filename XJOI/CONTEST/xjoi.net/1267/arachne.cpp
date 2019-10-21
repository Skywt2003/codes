#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int n,l[maxn],r[maxn];
int f[maxn][2];

inline int aabs(int x){
	return (x<0)?-x:x;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) l[i]=read(),r[i]=read();
	for (int i=2;i<=n;i++)
		f[i][0]=max(f[i-1][0]+aabs(l[i-1]-l[i]), f[i-1][1]+aabs(r[i-1]-l[i])),
		f[i][1]=max(f[i-1][0]+aabs(l[i-1]-r[i]), f[i-1][1]+aabs(r[i-1]-r[i]));

	printf("%lld\n",max(f[n][0],f[n][1]));
	return 0;
}