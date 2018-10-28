#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000005;
const long long INF=1e9;
int T,n,x[maxn],y[maxn];
long long seed;
long long A[maxn],B[maxn],maxa,mina,maxb,minb;

// A[i]=Xi+Yi;
// B[i]=Xi-Yi;

inline long long rand(long long l, long long r) { 
	static long long mo=1e9+7, g=78125; 
	return l+((seed*=g)%=mo)%(r-l+1); 
}

inline void build(int n,int seed){
	for (int i=0;i<n;i++)
		x[i]=rand(-1000000000,1000000000),
		y[i]=rand(-1000000000,1000000000),
		A[i]=x[i]+y[i],maxa=max(maxa,A[i]),mina=min(mina,A[i]),
		B[i]=x[i]-y[i],maxb=max(maxb,B[i]),minb=min(minb,B[i]);
}

inline void init(){
	maxa=maxb=-INF;
	mina=minb=INF;
}

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	T=read();
	while (T--){
		init();
		n=read();seed=read();
		build(n,seed);
		printf("%lld\n",max(maxa-mina,maxb-minb));
	}
	return 0;
}