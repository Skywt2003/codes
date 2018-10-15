#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=5005,maxv=10005,maxm=16005;
int n,m,s,t,tot=0,lnk[maxn],son[maxm],nxt[maxm],dst[maxn],que[maxv];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void BFS(){
	int head=0,tail=1;
	que[tail]=s;dst[s]=0;
	while (head!=tail){
		head=(head+1)%maxv;
		for (int i=lnk[que[head]];i;i=nxt[i]) if (dst[que[head]]+1<dst[son[i]]){
			dst[son[i]]=dst[que[head]]+1;
			tail=(tail+1)%maxv;
			que[tail]=son[i];
			if (son[i]==t) return;
		}
	}
}
int main(){
	memset(dst,63,sizeof(dst));
	int INF=dst[0];
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	s=read();t=read();
	BFS();
	if (dst[t]==INF) printf("-1\n"); else printf("%d\n",dst[t]);
	return 0;
}
