#include<cstdio>
#include<cstring>
#include<iostream>

#define clear(_) memset(_,0,sizeof(_))
#define write(_) cout<<#_<<" = "<<_<<endl;

using namespace std;
const int maxn=4*1048576+10;
int n;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

namespace TrieTree{
	int ls[maxn],rs[maxn],cnt;
	bool flag[maxn];
	inline void init(){
		clear(flag);
		clear(ls);clear(rs);
		cnt=0;
	}
	inline void make_subset(int x){ // 构造所有子集
		if (flag[x]) return;
		flag[x]=true;
		for (int i=0;i<20;i++) if (x&(1<<i)) make_subset(x^(1<<i));
	}
	inline void insert(int x){
		int now=0;
		for (int i=19;i>=0;i--) if (x&(1<<i)){
			if (!ls[now]) ls[now]=++cnt;
			now=ls[now];
		} else {
			if (!rs[now]) rs[now]=++cnt;
			now=rs[now];
		}
		make_subset(x);
	}
	inline int query(int k,int x){
		if (k==0){
			int now=0,num=0;
			for (int i=19;i>=0;i--) if (x&(1<<i)){
				if (rs[now]) now=rs[now]; else now=ls[now],num+=1<<i;
			} else {
				if (ls[now]) now=ls[now],num+=1<<i; else now=rs[now];
			}
			return x^num;
		} else if (k==1){ // 找出 x and y 的最大值
			int num=0;
			for (int i=19;i>=0;i--) if (x&(1<<i)){
				if (flag[num+(1<<i)]) num+=(1<<i);
			}
			return x&num;
		} else if (k==2){ // 找出 x or y 的最大值
			int now=0,num=0;
			for (int i=19;i>=0;i--) if (!(x&(1<<i))){
				if (flag[num+(1<<i)]) num+=(1<<i);
			}
			return x|num;
		}
	}
}

int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read();
		if (x==1){
			int y=read();
			TrieTree::insert(y);
		} else if (x==2){
			int q=read();
			printf("%d %d %d\n",TrieTree::query(0,q),TrieTree::query(1,q),TrieTree::query(2,q));
		} else if (x==3){
			int q=read();
			printf("%d\n",TrieTree::query(0,q));
		}
	}
	return 0;
}