#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=30005,maxe=150005;
int n,m,dst[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
bool vis[maxn];
struct HeapElementInfo{
	int dst,id;
    bool operator <(const HeapElementInfo bb)const{
        return dst>bb.dst;
    }
};
priority_queue<HeapElementInfo> heap;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void init(){
	memset(dst,0x3f,sizeof(dst));
}
inline void Dijkstra(){
	dst[1]=0;vis[1]=true;
	for (int i=lnk[1];i;i=nxt[i]) heap.push((HeapElementInfo){w[i],son[i]}),dst[son[i]]=w[i];
	for (int t=1;t<n&&!heap.empty();t++){
		HeapElementInfo now;
		for (;;){
			if (heap.size()==0) {printf("ERROR!\n");return;}
			now.id=heap.top().id;now.dst=heap.top().dst;heap.pop();
			if (now.dst==dst[now.id]&&!vis[now.id]) break;
		}
		vis[now.id]=true;
		for (int i=lnk[now.id];i;i=nxt[i]) if (!vis[son[i]]&&dst[now.id]+w[i]<dst[son[i]]){
			dst[son[i]]=dst[now.id]+w[i];
			heap.push((HeapElementInfo){dst[son[i]],son[i]});
		}
	}
}
int main(){
	n=read();m=read();
	init();
	for (int i=0;i<m;i++){
		int x=read(),y=read(),z=read(); // dst[y]-dst[x]<=z ==> dst[y]<=dst[x]+z
		add(x,y,z);
	}
	Dijkstra();
	printf("%d\n",dst[n]);
	return 0;
}