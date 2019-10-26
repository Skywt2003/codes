#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5;

int n,m,e;

class uniset{
	private:
		int fa[maxn];

	public:
		void init(int n){
			for (int i=1;i<=n;i++) fa[i]=i;
		}

		int getfa(int x){
			return (x==fa[x])?x:fa[x]=getfa(fa[x]);
		}

		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x==y) return;
			fa[x]=y;
		}
};

uniset u;
bool vis[maxn];

signed main(){
	n=read(); m=read(); e=read();
	if (e==0){printf("%lld\n",n);return 0;}
	u.init(n+m);
	for (int i=1;i<=e;i++){
		int x=read(),y=read();
		u.merge(x,y+n);
	}
	
	int num=0;
	for (int i=1;i<=n;i++) if (!vis[u.getfa(i)]) vis[u.getfa(i)]=true,num++;

	printf("%lld\n",num-1);
	return 0;
}