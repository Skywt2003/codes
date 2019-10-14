#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f;
const int maxn=10005,maxm=2005;

int n,m,k;
int x[maxn],y[maxn];
int low[maxn],high[maxn];
int f[maxn][maxm];

int num[maxn];

signed main(){
	n=read(); m=read(); k=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for (int i=1;i<=k;i++){
		int x=read();
		low[x]=read(),high[x]=read();
		low[x]++; high[x]--;
		num[x]++;
	}
	for (int i=1;i<=n;i++) if (!num[i]) low[i]=1,high[i]=m;
	for (int i=1;i<=n;i++) num[i]+=num[i-1];

	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=m;i++) f[0][i]=0;
	for (int i=1;i<=n;i++){
		for (int j=x[i]+1;j<=m+x[i];j++)
			f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
		for (int j=m+1;j<=m+x[i];j++)
			f[i][m]=min(f[i][m],f[i][j]);
		for (int j=1;j<=m-y[i];j++)
			f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
		for (int j=1;j<=low[i]-1;j++) f[i][j]=INF;
		for (int j=high[i]+1;j<=m;j++) f[i][j]=INF;
	}

	int ans=INF;
	for (int i=1;i<=m;i++) ans=min(ans,f[n][i]);
	if (ans==INF){
		printf("0\n");
		for (int i=n;i>=0;i--){
			for (int j=1;j<=m;j++)
				if (f[i][j]<INF) {ans=i;break;}
			if (ans!=INF) break;
		}
		printf("%d\n",num[ans]);
	} else printf("1\n%d\n",ans);

	return 0;
}