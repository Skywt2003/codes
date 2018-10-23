#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

#define int long long
using namespace std;
#define clear_arr(_) memset(_,0,sizeof(_))

const int maxn=10005,maxe=10005;
int n=0,m=0;
int fa[maxn];

int len1,len2;
char a[maxn],b[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],sons[maxn];
int deep[maxn];
stack <int> s;
vector<int> vec[maxn];
vector<int> rst[maxn];

inline void add(int x,int y){
	tot++;sons[x]++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline int write_that_there_is_not_any_answer(){
	printf("Impossible\n");
	return 0;
}

inline void write_that_there_is_an_answer(){
	printf("Possible\n");
}

inline void build_full_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]){
		deep[son[i]]=deep[x]+1;
		vec[deep[son[i]]].push_back(sons[son[i]]);
		build_full_tree(son[i]);
	}
}

inline void check(int x){
	for (int i=lnk[x];i;i=nxt[i]){
		deep[son[i]]=deep[x]+1;
		rst[deep[son[i]]].push_back(sons[son[i]]);
		check(son[i]);
	}
}

inline void clear_graph(){
	tot=0;
	clear_arr(fa);clear_arr(sons);clear_arr(deep);
	clear_arr(lnk);clear_arr(nxt);clear_arr(son);
}

inline bool cmp(int x,int y){
	return x>y;
}

signed main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	len1=strlen(a+1);len2=strlen(b+1);

	for (int i=1;i<=len1;i++){
		if (a[i]=='(') s.push(++n); else {
			int now=s.top();
			s.pop();
			fa[now]=s.empty()?-1:s.top();
			add(fa[now],now);
		}
	}
	deep[1]=1;vec[1].push_back(sons[1]);
	build_full_tree(1);

	clear_graph();
	for (int i=1;i<=len2;i++){
		if (b[i]=='(') s.push(++m); else {
			int now=s.top();
			s.pop();
			fa[now]=s.empty()?-1:s.top();
			add(fa[now],now);
		}
	}
	deep[1]=1;vec[1].push_back(sons[1]);
	check(1);

	for (int i=1;i<=len1;i++){
		if (vec[i].size()<rst[i].size()) return write_that_there_is_not_any_answer();
		sort(vec[i].begin(),vec[i].end(),cmp);
		sort(rst[i].begin(),rst[i].end(),cmp);
		for (int j=0;j<rst[i].size();j++) if (rst[i][j]>vec[i][j]) return write_that_there_is_not_any_answer();
	}
	write_that_there_is_an_answer();
	return 0;
}