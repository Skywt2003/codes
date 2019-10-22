#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;

const int maxn=1005,maxe=2005;

int T;
int n,m,x;
int ans=0;

struct edge{
	int x,y,z;
};
edge a[maxe];

class uniSet{
	private:
		int fa[maxn];
		int num;
	
	public:
		void init(int n){
			for (int i=0;i<=n;i++) fa[i]=i; num=0;
		}

		int getfa(int x){
			return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
		}

		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x!=y) fa[x]=y; num++;
		}

		int count(){
			return num;
		}
};

uniSet u;

signed main(){
	T=read();
	while (T--){
		ans=0;
		n=read(); m=read(); x=read();
		for (int i=0;i<m;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
		for (int i=1;i<(1<<m);i++){
			int sum=INF;
			for (int j=1;j<(1<<m);j++){
				u.init(n);
				int now=0;
				bool ar=false,br=false;
				for (int k=0;k<m;k++) if (j&(1<<k)){
					u.merge(a[k].x,a[k].y),now+=a[k].z;
					if (i&(1<<k)) ar=true; else br=true;
				}
				if (ar==false || br==false) continue;
				if (u.count() != n-1) continue;
				sum=min(sum,now);
			}
			if (sum==x) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}