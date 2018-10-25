#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
#define int long long
const int maxn=305,INF=1e8;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int T,n;
int a[maxn],b[maxn];
int f[maxn][maxn][maxn];
map<int,int> id;
int cnt,num[maxn];

inline int min3(int x,int y,int z){
	return min(x,y)<z?min(x,y):z;
}

inline void init(){
	memset(f,0x3f,sizeof(f));
	cnt=0;
	id.clear();
	memset(num,0,sizeof(num));
}

inline void make_id(){
	sort(b+1,b+1+n);
	for (int i=1;i<=n;){
		int j=i;
		while (j+1<=n && b[j+1]==b[i]) j++;
		id[b[i]]=++cnt;num[cnt]=b[i];i=j+1;
	}
}

inline void solve(){
	for (int i=1;i<=n;i++){
		for (int k=1;k<=cnt;k++) f[i][i][k]=((k==id[a[i]])?(0):(a[i]*num[k]));
	}
	for (int L=1;L<n;L++){
		for (int i=1;i<=n-L+1;i++){
			int j=i+L;
			for (int k=1;k<=cnt;k++){
				int t=id[a[i]],w=id[a[j]];
				f[i][j][k]=min3(f[i][j][k],f[i+1][j][k]+((k==t)?(0):(num[k]*a[i])), f[i][j-1][k]+((k==w)?(0):(num[k]*a[j])));
				f[i][j][t]=min(f[i][j][t],f[i+1][j][k]+((t==k)?(0):(num[k]*a[i]*(j-i))));
				f[i][j][w]=min(f[i][j][w],f[i][j-1][k]+((w==k)?(0):(num[k]*a[j]*(j-i))));
			}
		}
	}
}

signed main(){
	freopen("colour.in","r",stdin);
	freopen("colour.out","w",stdout);
	T=read();
	while (T--){
		init();
		n=read();
		for (int i=1;i<=n;i++) a[i]=b[i]=read();
		make_id();
		solve();
		int ans=INF;
		for (int i=1;i<=cnt;i++) ans=min(ans,f[1][n][i]);
		printf("%lld\n",ans);
	}
	return 0;
}