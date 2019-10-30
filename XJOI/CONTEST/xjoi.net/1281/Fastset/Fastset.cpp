#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3e5+5;

int n;
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
int f[maxn][22],deep[maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	for (int j=1;j<21;j++)
		f[x][j]=f[f[x][j-1]][j-1];
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]){
		f[to[i]][0]=x; deep[to[i]]=deep[x]+1;
		build_tree(to[i]);
	}
}

int get_lca(int x,int y){
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=20;i>=0;i--) if (deep[f[x][i]] >= deep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int get_dist(int x,int y){
	int l=get_lca(x,y);
	return deep[x]-deep[l]+deep[y]-deep[l];
}

struct node{
	int pos,id;
	bool operator <(node bb)const{return id < bb.id;}
	bool operator >(node bb)const{return id > bb.id;}
};
set<node> s;
// set<node>::iterator it;

int ans=0;

#define sit set<node>::iterator
int work(int x,int y,int t){
	sit sl=s.lower_bound((node){0,x}),sr=s.upper_bound((node){0,y}); sl--;
	#ifdef DEBUG
		// printf("Found in set: %lld ... %lld\n",(*sl).id,(*sr).id);
	#endif

	vector<node> vec;vec.clear();
	for (sit i=sl;;i++) {vec.push_back(*i);if (i==sr) break;}
	for (int i=1;i<vec.size()-1;i++) s.erase(vec[i]);

	int ret=0,last_id=x;
	for (int i=1;i<vec.size();i++){
		ret+=(min(y+1,vec[i].id)-last_id) * get_dist(vec[i-1].pos,t);
		last_id=vec[i].id;
	}
	s.insert((node){t,x});
	if (vec.size()!=0 && vec[vec.size()-1].id>y+1) s.insert((node){vec[vec.size()-2].pos,y+1});
	return ret;
}
#undef sit

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}

	deep[1]=1; build_tree(1);

	s.clear();
	s.insert((node){0,0});
	for (int i=1;i<=n;i++) s.insert((node){i,i});
	s.insert((node){0,n+1});

	for (int i=1;i<=n;i++){
		int x=read(),y=read(),t=read();
		ans+=work(x,y,t);
	}

	printf("%lld\n",ans);
	return 0;
}