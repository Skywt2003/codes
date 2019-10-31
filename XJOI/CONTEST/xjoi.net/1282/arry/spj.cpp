#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;

int n,k,p[maxn],q[maxn],a[maxn],b[maxn];

signed main(){
	freopen("data.in","r",stdin);
	n=read();k=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) q[i]=read();
	freopen("my.out","r",stdin);
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();

	for (int i=1;i<n;i++)
		if ((!(a[p[i]]<=a[p[i+1]])) || (!(b[q[i]]<=b[q[i+1]]))) return 1;

	int cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			cnt+=a[j]+b[i]<0;

	if (cnt==k) printf("Accepted\n");
	return 0;
}