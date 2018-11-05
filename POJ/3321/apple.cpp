#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=1e5+5;

int n,q;

namespace BIT{
	int tree[maxn];

	inline int lowbit(int x){
		return x&(-x);
	}

	inline void update(int x,int delta){
		while (x<=n) tree[x]+=delta,x+=lowbit(x);
	}

	inline int query(int x){
		int ret=0;
		while (x) ret=ret+tree[x],x-=lowbit(x);
		return ret;
	}
}

namespace Graph{
	int tot=0,lnk[maxn],nxt[maxn],son[maxn];
}

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline char read_char(){
	char ch=getchar();
	while (ch!='C' && ch!='Q') ch=getchar();
	return ch;
}

signed main(){

}