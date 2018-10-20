#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=1005,maxe=2005;
const int INF=(int)1e18;

int n;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int ans=INF;
vector<int> anses;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void init(){
	tot=0;
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(son,0,sizeof(son));
	anses.clear();ans=INF;
}

inline int DFS(int x,int fa){
	vector<int> vec;
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa){
		vec.push_back(DFS(son[i],x));
	}
	if (vec.size()==0) return 0;
	sort(vec.begin(),vec.end());
	int ret=0,now=vec.size();
	for (int i=0;i<vec.size();i++){
		ret=max(ret,vec[i]+now);
		now--;
	}
	return ret;
}

signed main(){
	while (~scanf("%lld",&n)){
		init();
		for (int i=2;i<=n;i++){
			int x=read();
			add(i,x);add(x,i);
		}
		for (int i=1;i<=n;i++){
			int now=DFS(i,-1);
			if (now<ans){
				ans=now;
				anses.clear();
				anses.push_back(i);
			} else if (now==ans) anses.push_back(i);
		}
		printf("%lld\n",ans+1);
		for (int i=0;i<anses.size();i++) printf("%lld ",anses[i]);
		printf("\n");
	}
	return 0;
}