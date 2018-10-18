#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=10005,maxe=500005;
int n,m,s,t,tot=0,dst[maxn],lnk[maxn],nxt[maxe],son[maxe],w[maxe];
bool vis[maxn];
struct WT{
	int num,x;
	bool operator <(const WT bb)const{return num>bb.num;}
};
priority_queue <WT> heap;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y,int z){tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;}
int main(){
	while (heap.size()) heap.pop();
	n=read();m=read();s=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);
	}
	int INF=2147483647;
	for (int i=1;i<=n;i++) dst[i]=INF;
	dst[s]=0;heap.push((WT){0,s});
	for (;heap.size()>0;){
		while (vis[heap.top().x]) heap.pop();int k=heap.top().x;heap.pop();vis[k]=1;
		for (int j=lnk[k];j;j=nxt[j]) if ((!vis[son[j]])&&(dst[k]+w[j]<dst[son[j]])) vis[son[j]]=1,dst[son[j]]=dst[k]+w[j],heap.push((WT){dst[son[j]],son[j]});
	}
	for (int i=1;i<n;i++) printf("%d ",dst[i]);
	printf("%d\n",dst[n]);
	return 0;
}
