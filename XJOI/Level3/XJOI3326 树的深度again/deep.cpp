#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005,maxe=200005;
int n,tot=0,lnk[maxn],nxt[maxe],son[maxe],deep=1;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y){
	tot++;
	son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void DFS(int x,int now_deep){
	if (now_deep>deep) deep=now_deep;
	for (int i=lnk[x];i;i=nxt[i]) DFS(son[i],now_deep+1);
}
int main(){
	n=read();
	for (int i=2;i<=n;i++){
		int x=read();
		add(x,i);
	}
	DFS(1,1);
	printf("%d\n",deep);
	return 0;
}
