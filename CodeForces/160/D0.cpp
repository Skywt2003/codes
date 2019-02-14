#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
int n,m;

struct edge{
	int x,y,w;
	int ans,id; // 1:none   2:at least one   3:any
	bool toadd;
}a[maxn];

bool cmp(edge aa,edge bb){return aa.w<bb.w;}
bool cmp_id(edge aa,edge bb){return aa.id<bb.id;}

namespace UniSet{
	int fa[maxn];

	void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i;
	}
	int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}
}
namespace UniSet2{
	int fa[maxn];

	void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i;
	}
	int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}
	void merge(int x,int y){
		x=getfa(x);y=getfa(y);
		if (x!=y) fa[x]=y;
	}
}

int tot=0,son[maxn],nxt[maxn],lnk[maxn],vis[maxn],eid[maxn];
void add_edge(int x,int y,int id){
	tot++;eid[tot]=id;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
	cout<<x<<" -- "<<y<<" id= "<<a[id].id<<endl;
}

void DFS(int x,int faid){
	for (int i=lnk[x];i;i=nxt[i]) if (eid[i]!=faid){
		int nf=UniSet2::getfa(son[i]);
		if (vis[nf]==0) vis[nf]=1,DFS(nf,eid[i]); else 
		if (vis[nf]==1){
			a[eid[i]].ans=2;
			cout<<"ID="<<a[eid[i]].id<<" fucked"<<endl;
			vis[nf]=-1;
			DFS(nf,eid[i]);
		}
	}
	vis[x]=-1;
}

signed main(){
	n=read();m=read();
	UniSet::init(n);UniSet2::init(n);
	for (int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].w=read(),a[i].ans=1,a[i].id=i;

	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m;){
		int j=i;
		while (j+1<=m && a[j+1].w==a[i].w) j++;
		if (i==j){
			int fx=UniSet::getfa(a[i].x),fy=UniSet::getfa(a[i].y);
			if (fx==fy) {i++;continue;}
			a[i].ans=3;
			UniSet::fa[fx]=fy;
			UniSet2::merge(a[i].x,a[i].y);
		} else {
			for (int k=i;k<=j;k++){
				int fx=UniSet::getfa(a[k].x),fy=UniSet::getfa(a[k].y);
				if (fx!=fy) UniSet::fa[fx]=fy;
				a[k].toadd=true;
				a[k].ans=3;
			}
		}
		i=j+1;
	}
	for (int i=1;i<=m;i++) if (a[i].toadd){
		int fx=UniSet2::getfa(a[i].x),fy=UniSet2::getfa(a[i].y);
		add_edge(fx,fy,i);add_edge(fy,fx,i);
	}

	vis[UniSet2::getfa(1)]=1;
	DFS(UniSet2::getfa(1),-1);

	sort(a+1,a+1+m,cmp_id);
	for (int i=1;i<=m;i++){
		if (a[i].ans==1) printf("none\n"); else
		if (a[i].ans==2) printf("at least one\n"); else
		if (a[i].ans==3) printf("any\n");
	}

	return 0;
}