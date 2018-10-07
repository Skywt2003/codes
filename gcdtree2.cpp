/*
 * XJOI CONTEST1006 T1 GCD生成树
 * 180927 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long
const int INF=(long long)1<<60;

const int maxn=100005;
int n,a[maxn],N=0,ans=0;
bool vis[maxn],now[maxn];
int fa[maxn];

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

inline int getfa(int x){
	if (fa[x]==x) return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read(),N=max(N,a[i]);
		if (vis[a[i]]) ans+=a[i]; else vis[a[i]]=true;
	}
	for (int i=1;i<=N;i++) fa[i]=i;
	for (int i=N;i>=1;i--){
		int cnt=0;
		for (int k=1;i*k<=N;k++) if (vis[i*k]){
			int f=getfa(i*k);
			if (!now[f]) now[f]=true,cnt++;
		}
		if (cnt>1) ans+=(cnt-1)*i;
		for (int k=1;i*k<=N;k++) if (vis[i*k]){
			int f=getfa(i*k);
			if (now[f]) now[f]=false,fa[f]=i;
		}
	}
	printf("%lld\n",ans);
	return 0;
}