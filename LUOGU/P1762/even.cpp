#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=1000003;

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

int lowbit(int x){
	return x&(-x);
}

int upbit(int x){
	for (int i=1ll;;i<<=1) if (i>=x) return i/2;
	return 0;
}

int DFS(int x){
	if (lowbit(x)==x) return qsm(3,log2(x));
	int now=upbit(x);
	return (qsm(3,log2(now)) + 2*DFS(x-now)%tt)%tt;
}

int n;

signed main(){
	n=read();
	int odd=DFS(n);
	int sum=(n+1)%tt*(n%tt)%tt*qsm(2,tt-2)%tt; // 可能会乘爆……
	printf("%lld\n",((sum-odd)%tt+tt)%tt);
	return 0;
}