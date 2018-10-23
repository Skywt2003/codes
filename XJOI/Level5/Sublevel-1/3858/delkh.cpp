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

int len1,len2;
char a[maxn],b[maxn];
stack <int> s;

namespace tree1{
	int fa[maxn];
	int tot=0,lnk[maxn],nxt[maxe],son[maxe],sons[maxn];

	inline void add(int x,int y){
		tot++;sons[x]++;son[tot]=y;
		nxt[tot]=lnk[x];lnk[x]=tot;
	}
}

namespace tree2{
	int fa[maxn];
	int tot=0,lnk[maxn],nxt[maxe],son[maxe],sons[maxn];

	inline void add(int x,int y){
		tot++;sons[x]++;son[tot]=y;
		nxt[tot]=lnk[x];lnk[x]=tot;
	}
}

inline bool check(int x,int y){
	int now=tree1::lnk[x];
	for (int i=tree2::lnk[y];i;i=tree2::nxt[i]){
		while (now!=0 && (!check(tree1::son[now],tree2::son[i]))) now=tree1::nxt[now];
		if (now==0) return false;
		now=tree1::nxt[now];
	}
	return true;
}

signed main(){
	scanf("%s",a+1);len1=strlen(a+1);
	scanf("%s",b+1);len2=strlen(b+1);

	for (int i=1;i<=len1;i++){
		if (a[i]=='(') s.push(++n); else {
			int now=s.top();
			s.pop();
			tree1::fa[now]=s.empty()?-1:s.top();
			tree1::add(tree1::fa[now],now);
		}
	}

	for (int i=1;i<=len2;i++){
		if (b[i]=='(') s.push(++m); else {
			int now=s.top();
			s.pop();
			tree2::fa[now]=s.empty()?-1:s.top();
			tree2::add(tree2::fa[now],now);
		}
	}

	printf(check(1,1)?"Possible":"Impossible");
	return 0;
}