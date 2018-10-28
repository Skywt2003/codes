#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=800005;
int n,m,tree[maxn],a[maxn/4];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline char read_ch(){
	char ch=getchar();
	while (ch!='U'&&ch!='Q') ch=getchar();
	return ch;
}
inline void init(){
	memset(a,0,sizeof(a));
	memset(tree,0,sizeof(tree));
}
inline void BuildTree(int p,int tl,int tr){
	if (tl==tr) {tree[p]=a[tl];return;}
	int mid=((tr-tl)>>1)+tl;
	BuildTree(p<<1,tl,mid);
	BuildTree((p<<1)+1,mid+1,tr);
	tree[p]=max(tree[p<<1],tree[(p<<1)+1]);
	//printf("Tree[%d]= %d\n",p,tree[p]);
}
inline int query(int p,int tl,int tr,int sl,int sr){
	if (sl<=tl&&tr<=sr) return tree[p];
	if (tl>tr) return 0;
	int mid=((tr-tl)>>1)+tl,ret=0;
	if (sl<=mid) ret=max(ret,query(p<<1,tl,mid,sl,sr));
	if (mid+1<=sr) ret=max(ret,query((p<<1)+1,mid+1,tr,sl,sr));
	return ret;
}
inline void update(int p,int tl,int tr,int s,int delta){
	if (tl>tr) return;
	if (tr<s||tl>s) return;
	if (tl==tr&&tl==s){
		tree[p]=delta;
		return;
	}
	int mid=((tr-tl)>>1)+tl;
	if (s<=mid) update(p<<1,tl,mid,s,delta);
	if (mid+1<=s) update((p<<1)+1,mid+1,tr,s,delta);
	tree[p]=max(tree[p<<1],tree[(p<<1)+1]);
}
int main(){
	while (scanf("%d%d",&n,&m)!=-1){
		init();
		for (int i=1;i<=n;i++) a[i]=read();
		BuildTree(1,1,n);
		for (int j=1;j<=m;j++){
			char now=read_ch();
			if (now=='Q'){
				int x=read(),y=read();
				printf("%d\n",query(1,1,n,x,y));
			} else {
				int x=read(),y=read();
				update(1,1,n,x,y);
			}
		}
	}
	return 0;
}