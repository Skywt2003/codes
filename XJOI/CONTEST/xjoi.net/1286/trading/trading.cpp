#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;

const int maxn=506;

int n,w,alls;
int dist[maxn][maxn];
int ans=0;

void Floyd(){
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++) if (k!=i)
			for (int j=0;j<n;j++) if (i!=j && k!=j)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

signed main(){
	memset(dist,0x3f,sizeof(dist));
	n=read(); w=read(); alls=1<<n;
	for (int i=1;i<n;i++){
		int x=read()-1,y=read()-1,z=read();
		dist[x][y]=dist[y][x]=z;
	}
	Floyd();

	for (int s=0;s<alls;s++) if (__builtin_popcountll(s) == w){
		int now=0;
		for (int i=0;i<n;i++) if (s&(1<<i))
			for (int j=i+1;j<n;j++) if (s&(1<<j))
				now+=dist[i][j];
		for (int i=0;i<n;i++) if (!(s&(1<<i)))
			for (int j=i+1;j<n;j++) if (!(s&(1<<j)))
				now+=dist[i][j];
		ans=max(ans,now);
	}

	printf("%lld\n",ans);
	return 0;
}