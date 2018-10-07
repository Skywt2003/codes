/*
 * XJOI CONTEST1002 T4 树上的石头
 * 180924 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005,maxe=2005;
int n,w[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int f[maxn];

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline bool compare(int i,int j){
	return f[i]-w[i]>f[j]-w[j];
}

inline void make_answer(int x,int fa){
	vector<int> now;now.clear();
	f[x]=w[x];
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa){
		make_answer(son[i],x);
		f[x]+=w[son[i]];
		now.push_back(son[i]);
	}
	sort(now.begin(),now.end(),compare);
	int sum=0;
	for (int i=0;i<now.size();i++){
		f[x]=max(f[x],f[now[i]]+sum);
		sum+=w[now[i]];
	}
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read();
		add(x,i);add(i,x);
	}
	for (int i=0;i<n;i++) w[i]=read();
	make_answer(0,-1);
	printf("%lld\n",f[0]);
	return 0;
}