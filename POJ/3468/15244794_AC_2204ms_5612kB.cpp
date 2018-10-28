#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2000005;
int n,m;
long long a[maxn],tree[maxn],tag[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline long long llread(){
	long long ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=(long long)-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*(long long)10+(long long)(ch-'0'),ch=getchar();
	return (long long)ret*f;
}
inline char read_ch(){
	char ch=getchar();
	while (ch!='Q'&&ch!='C') ch=getchar();
	return ch;
}
inline void BuildTree(int p,int tl,int tr){
	tag[p]=0;
	if (tl==tr) {tree[p]=a[tl];return;}
	int mid=((tr-tl)>>1)+tl;
	BuildTree((p<<1)  ,tl,mid  );
	BuildTree((p<<1)+1,mid+1,tr);
	tree[p]=tree[p<<1]+tree[(p<<1)+1];
}
inline void push_down(int tl,int tr,int p){
	int mid=((tr-tl)>>1)+tl;
	tree[p<<1]+=(long long)tag[p]*(mid-tl+1);
	tag[p<<1]+=tag[p];
	tree[(p<<1)+1]+=(long long)tag[p]*(tr-mid);
	tag[(p<<1)+1]+=tag[p];
	tag[p]=0;
}
inline void update(int sl,int sr,int tl,int tr,long long delta,int p){
	if (sl<=tl&&sr>=tr){
		tree[p]+=delta*(long long)(tr-tl+1);
		tag[p]+=delta;
		return;
	}
	push_down(tl,tr,p);
	int mid=((tr-tl)>>1)+tl;
	if (sl<=mid) update(sl,sr,tl,mid,delta,p<<1);
	if (mid<sr)  update(sl,sr,mid+1,tr,delta,(p<<1)+1);
	tree[p]=tree[p<<1]+tree[(p<<1)+1];
}
inline long long query(int sl,int sr,int tl,int tr,int p){
	if (sl<=tl&&sr>=tr) return tree[p];
	long long ret=0;
	push_down(tl,tr,p);
	int mid=((tr-tl)>>1)+tl;
	if (sl<=mid) ret+=(long long)query(sl,sr,tl,mid,p<<1);
	if (mid<sr)  ret+=(long long)query(sl,sr,mid+1,tr,(p<<1)+1);
	return ret;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=llread();
	BuildTree(1,1,n);
	for (int i=1;i<=m;i++){
		int c=read_ch();
		if (c=='C'){
			int x=read(),y=read();
			long long z=llread();
			update(x,y,1,n,z,1);
		} else {
			int x=read(),y=read();
			printf("%lld\n",query(x,y,1,n,1));
		}
	}
	return 0;
}
