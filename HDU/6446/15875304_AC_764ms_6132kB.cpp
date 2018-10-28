#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<iostream>
#define CLEAR(x) memset(x,0,sizeof(x))
using namespace std;
const int maxn=100005,tt=1000000007;
int n;
int tot,lnk[maxn],nxt[maxn*2],son[maxn*2],w[maxn*2];
bool vis[maxn];

int sum_dfs;
long long lst[maxn],lstw[maxn],total;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void init(){
	tot=0;
	CLEAR(lnk);CLEAR(nxt);CLEAR(son);CLEAR(w);
	CLEAR(lst);CLEAR(lstw);CLEAR(vis);
	sum_dfs=total=0;
}

inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline long long GetSum(int x){
    sum_dfs++;
    vis[x]=true;
    total=((long long)total+lst[x])%tt;
    long long van=0;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
        lst[son[i]]=((long long)lst[x]+(long long)sum_dfs*w[i]%tt)%tt;
        long long nowvan=GetSum(son[i])%tt;
        lst[x]+=((long long)lstw[son[i]]+(long long)nowvan*w[i]%tt)%tt;
        lstw[x]+=((long long)lstw[son[i]]+(long long)nowvan*w[i]%tt)%tt;
        van=van+nowvan;
    }
    van++;
    return van;
}

long long fac(int x){
	long long ret=1;
	for (int i=2;i<=x;i++) ret=(ret*i)%tt;
	return ret;
}

int main(){
	while (scanf("%d",&n)!=-1){
		init();
		for (int i=1;i<n;i++){
			int x=read(),y=read(),z=read();
			add(x,y,z%tt);add(y,x,z%tt);
		}
		for (int i=1;i<=n;i++) if (nxt[lnk[i]]==0){
			GetSum(i);break;
		}
		// printf("TOTAL=%lld\n",total);
		total=(total*2)%tt;
		printf("%lld\n",(long long)total*(long long)fac(n-1)%tt);
	}
	return 0;
}