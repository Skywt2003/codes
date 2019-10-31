#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2005;

int n,m,a[maxn],nxt[maxn];
int l[maxn],r[maxn],g[maxn];
int f[2][maxn][maxn];
int ans=0;

void fix(int &x,int y){
	x=max(x,y);
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif

	n=read();m=read();
	int last=0;
	for (int i=1;i<=n;i++){
		a[i]=read();
		if (a[i]) while (last<i) nxt[last]=i,last++;
	}
	while (last<n) nxt[last]=n+1,last++;

	for (int i=1;i<=m;i++) l[i]=read(),r[i]=read(),g[i]=read();

	for (int i=0;i<=m;i++){
		memset(f[i&1^1],0,sizeof(f[i&1^1]));
		for (int j=0;j<=r[i];j++){
			for (int k=0;k<=a[j];k++){
				ans=max(ans,f[i&1][j][k]);
				if (i==m) continue;
				fix(f[i&1^1][j][k],f[i&1][j][k]);
				if (j<l[i+1]){
					if (a[l[i+1]]>0) fix(f[i&1^1][l[i+1]][1],f[i&1][j][k]+g[i+1]);
					else if (nxt[l[i+1]]<=r[i+1]) fix(f[i&1^1][nxt[l[i+1]]][1],f[i&1][j][k]+g[i+1]);
				} else {
					if (k+1<=a[j]) fix(f[i&1^1][j][k+1],f[i&1][j][k]+g[i+1]);
					if (nxt[j]<=r[i+1]) fix(f[i&1^1][nxt[j]][1],f[i&1][j][k]+g[i+1]);
				}
			}
		}
	}

	printf("%lld\n",ans);
	return 0;
}