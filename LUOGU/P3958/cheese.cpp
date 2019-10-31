#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define sqr(_) ((_)*(_))

const int maxn=1005;

class uniset{
	private:
		int fa[maxn];

	public:
		void init(int n){
			for (int i=1;i<=n;i++) fa[i]=i;
		}

		int getfa(int x){
			return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
		}

		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x==y) return;
			fa[x]=y;
		}
};

uniset u;

int T;
int n,h,r;

struct node{
	int x,y,z;
}a[maxn];

int get_dist(node a,node b){
	return sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z);
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif
	T=read();
	while (T--){
		n=read(); h=read(); r=read();
		for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();

		u.init(n);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) if (i!=j)
				if (get_dist(a[i],a[j]) <= sqr(2*r)) u.merge(i,j);
		
		bool suc=false;
		for (int i=1;i<=n&&suc==false;i++) if (h-a[i].z<=r)
			for (int j=1;j<=n&&suc==false;j++) if (a[j].z<=r){
				if (u.getfa(i)==u.getfa(j)) suc=true;
			}

		puts(suc?"Yes":"No");
	}
	return 0;
}