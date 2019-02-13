#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1505,INF=2e9;
int n;
int tot=0,lnk[maxn],nxt[maxn*2],son[maxn*2],fa[maxn],num[maxn];

inline void add_edge(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

struct point{
	int id,x,y;
};
double cross(double x1,double y1,double x2,double y2){
	return (x1*y2-x2*y1);
}
double compare(point a,point b,point c){
	return cross((b.x-a.x),(b.y-a.y),(c.x-a.x),(c.y-a.y));
}

point a[maxn];
point s,cc;
int ans[maxn];

void build_tree(int x){
	num[x]=1;
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]) fa[son[i]]=x,build_tree(son[i]),num[x]+=num[son[i]];
}

bool cmp(point a,point b){
	if(compare(cc,a,b)==0)
		return a.x>b.x;
	else return compare(cc,a,b)>0;
}

inline void DFS(int id,int p,vector<point> vec){
	ans[id]=p;
	cc=a[id];
	sort(vec.begin(),vec.end(),cmp);
	// printf("%lld:%lld -- ",id,p);
	// for (int i=0;i<(int)vec.size();i++) printf("%lld ",vec[i].id);printf("\n");
	vector<point> vec_nxt; point nxt_s;
	int j=0;
	for (int i=lnk[p];i;i=nxt[i]) if (son[i]!=fa[p]){
		vec_nxt.clear();nxt_s.y=INF;  int tmp=0;
		for (int k=j;k<j+num[son[i]]+tmp;k++){
			if (vec[k].id==id) {tmp=1;continue;}
			vec_nxt.push_back(vec[k]);
			if (vec[k].y<nxt_s.y) nxt_s=vec[k];
		}
		j+=num[son[i]]+tmp;
		DFS(nxt_s.id,son[i],vec_nxt);
	}
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	build_tree(1);
	vector<point> all_vec;all_vec.clear();
	s.y=INF;
	for (int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();a[i].id=i;
		all_vec.push_back(a[i]);
		if (a[i].y<s.y) s=a[i];
	}
	DFS(s.id,(int)1,all_vec);
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);printf("\n");
	return 0;
}