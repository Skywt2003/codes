#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int read_char(){
	char ch=getchar();
	while (ch!='A' && ch!='X' && ch!='R' && ch!=-1) ch=getchar();
	if (ch==-1) return -1;
	if (ch=='A') return 0; else
	if (ch=='R') return 1; else return 2;
}

const int maxn=20005,N=20000;

namespace BIT{
	int tree[maxn*4];
	
	int lowbit(int x){
		return x&(-x);
	}
	
	void clear(){
		memset(tree,0,sizeof(tree));
	}
	
	void update(int x,int delta){
		while (x<=N) tree[x]^=delta,x+=lowbit(x);
	}
	
	int query(int x){
		int ret=0;
		while (x>0) ret^=tree[x],x-=lowbit(x);
		return ret;
	}
}

signed main(){
	BIT::clear();
	int now=read_char();
	while (now!=-1){
		if (now==0||now==1){
			int x=read();
			BIT::update(x,x);
		} else {
			int x=read(),y=read();
			if (x>y) printf("0\n"); else
			printf("%lld\n",BIT::query(y)^BIT::query(x-1));
		}
		now=read_char();
	}
	return 0;
}
