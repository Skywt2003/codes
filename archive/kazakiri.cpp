/*
 * XJOI CONTEST1005 T2 ⻛斩冰华 (Kazakiri)
 * 180925 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=5e5+5,maxe=1e6+5;
int n,k;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int f[maxn][3]; // F[i][0/1/2]: 节点 i 没被删/先于父亲被删/后于父亲被删，其子树答案最大值

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline int max3(int a,int b,int c){
	return max(a,b)>c?max(a,b):c;
}

inline void make_dp(int x,int fa){
	// write_2(x,fa);
	priority_queue <int> heap;
	while (!heap.empty()) heap.pop();
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa){
		make_dp(son[i],x);
		f[x][0]=max3(f[x][0],f[son[i]][0],f[son[i]][1]);
		heap.push(max(f[son[i]][0],f[son[i]][2])-f[son[i]][1]);
	}
	int sum=0;
	for (int i=1;i<k&&(!heap.empty());i++) sum+=heap.top(),heap.pop();
	f[x][1]=sum+1;
	if (!heap.empty()) sum+=heap.top(),heap.pop();
	f[x][2]=sum+1;
}

signed main(){
	n=read();k=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	make_dp(1,-1);
	printf("%lld\n",max3(f[1][0],f[1][1],f[1][2]));
	return 0;
}