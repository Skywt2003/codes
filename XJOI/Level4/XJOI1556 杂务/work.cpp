#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10005,maxe=maxn*100,maxv=20005;
int n,tot=0,aans=0,lnk[maxn],son[maxe],nxt[maxe],t[maxn],f[maxn],que[maxv],ans[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y){
	tot++;f[y]++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		read();t[i]=read();
		int now=read();
		while (now) add(i,now),now=read();
	}
	int head=0,tail=0;
	for (int i=1;i<=n;i++) if (f[i]==0) que[++tail]=i,ans[i]=t[i];
	while (head<=tail){
		head=(head+1)%maxv;
		for (int i=lnk[que[head]];i;i=nxt[i]) if (f[son[i]]){
			if (ans[que[head]]+t[son[i]]>=ans[son[i]]) ans[son[i]]=ans[que[head]]+t[son[i]];
			f[son[i]]--;
			if (f[son[i]]==0) tail=(tail+1)%maxv,que[tail]=son[i];
			if (ans[son[i]]>aans) aans=ans[son[i]];
		}
	}
	printf("%d\n",aans);
	return 0;
}
