/*
 * XJOI CONTEST1006 T3 方格问题（暴力）
 * 180926 By SkyWT
 */

#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

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
	int ret=0,a=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') a=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*a;
}

#define int long long
const int INF=(long long)1<<60;

const int maxn=5005;
int n,m,k,q;
int a[maxn][maxn];
bool vis[maxn][maxn];

namespace SegmentTree{
	const int bigmaxn=1e5+5;
	int tag[bigmaxn*4],tree[bigmaxn*4];
	inline void push_down(int tl,int tr,int p){
		int mid=((tr-tl)>>1)+tl;
		tree[p<<1]=max(tree[p<<1],tag[p]);
		tag[p<<1]+=tag[p];
		tree[(p<<1)+1]=max(tree[(p<<1)+1],tag[p]);
		tag[(p<<1)+1]+=tag[p];
		tag[p]=0;
	}
	inline void update(int sl,int sr,int tl,int tr,int delta,int p){
		if (sl<=tl&&sr>=tr){
			tree[p]+=delta;
			tag[p]+=delta;
			return;
		}
		push_down(tl,tr,p);
		int mid=((tr-tl)>>1)+tl;
		if (sl<=mid) update(sl,sr,tl,mid,delta,p<<1);
		if (mid<sr)  update(sl,sr,mid+1,tr,delta,(p<<1)+1);
		tree[p]=max(tree[p<<1],tree[(p<<1)+1]);
	}
	inline int query(int sl,int sr,int tl,int tr,int p){
		if (sl<=tl&&sr>=tr) return tree[p];
		int ret=0;
		push_down(tl,tr,p);
		int mid=((tr-tl)>>1)+tl;
		if (sl<=mid) ret=max(ret,query(sl,sr,tl,mid,p<<1));
		if (mid<sr)  ret=max(ret,query(sl,sr,mid+1,tr,(p<<1)+1));
		return ret;
	}
}

inline signed SpecialSolution(){
	while (q--){
		int cmd=read();
		int x1=read(),y1=read(),x2=read(),y2=read();
		if (cmd==1){
			int delta=read();
			SegmentTree::update(y1,y2,1,m,delta,1);
		} else {
			int now=SegmentTree::query(y1,y2,1,m,1);
			printf((now>=k)?"no\n":"yes\n");
		}
	}
	return 0;
}

signed main(){
	n=read();m=read();k=read();q=read();
	if (n==1) return SpecialSolution();
	while (q--){
		int cmd=read();
		int x1=read(),y1=read(),x2=read(),y2=read();
		if (cmd==1){
			int delta=read();
			for (int i=x1;i<=x2;i++)
			for (int j=y1;j<=y2;j++)
				a[i][j]+=delta;
		} else {
			vis[x1][y1]=true;
			for (int i=x1;i<=x2;i++)
			for (int j=y1;j<=y2;j++){
				if (i==x1&&j==y1) continue;
				if (a[i][j]>=k) {vis[i][j]=false;continue;}
				vis[i][j]=((i-1>=x1)?vis[i-1][j]:false) || ((j-1>=y1)?vis[i][j-1]:false);
			}
			if (vis[x2][y2]) printf("yes\n"); else printf("no\n");
		}
	}
	return 0;
}