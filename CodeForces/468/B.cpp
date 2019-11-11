#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int n,A,B;
int a[maxn];

class uniset{
	int fa[maxn];
	int cnt;

	public:
		void init(int n){
			for (int i=1;i<=n;i++) fa[i]=i;
			cnt=n;
		}

		int getfa(int x){
			return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
		}

		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x==y) return;
			fa[x]=y; cnt--;
		}

		int count(){
			return cnt;
		}
};

uniset u;

set<pair<int,int> > s;
bool ina[maxn],inb[maxn];

signed main(){
	memset(ina,true,sizeof(ina));
	memset(inb,true,sizeof(inb));

	n=read();A=read(),B=read(); u.init(n);
	for (int i=1;i<=n;i++) a[i]=read(),s.insert(make_pair(a[i],i));

	for (int i=1;i<=n;i++){
		pair<int,int> now; set<pair<int,int> >::iterator it;

		now=make_pair(A-a[i],0); it=s.lower_bound(now);
		if (it == s.end()) ina[i]=false; else
		if ((*it).first == A-a[i]) u.merge(i,(*it).second); else ina[i]=false;

		now=make_pair(B-a[i],0); it=s.lower_bound(now);
		if (it == s.end()) inb[i]=false; else
		if ((*it).first == B-a[i]) u.merge(i,(*it).second); else inb[i]=false;

		if (!ina[i] && !inb[i]) {printf("NO\n");return 0;}
	}

	for (int i=1;i<=n;i++) ina[u.getfa(i)]&=ina[i],inb[u.getfa(i)]&=inb[i];
	for (int i=1;i<=n;i++) if (!ina[u.getfa(i)] && !inb[u.getfa(i)]){printf("NO\n");return 0;}

	printf("YES\n");
	for (int i=1;i<=n;i++) printf("%d ",inb[u.getfa(i)]);
	return 0;
}