#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int x,y,n,m,L;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int exgcd(int a,int b,int &x,int &y){
	if (b==0){
		x=1,y=0;
		return a;
	}
	int ret=exgcd(b,a%b,x,y);
	int t=x; x=y; y=t-a/b*y;
	return ret;
}

signed main(){ // (n-m)a + (L)b = y-x;
	x=read(),y=read(),n=read(),m=read(),L=read();
	if (n<m) swap(n,m),swap(x,y);

	int xx,yy;
	int g=exgcd(n-m,L,xx,yy);
	if ((y-x)%g) {printf("Impossible\n");return 0;}
	printf("%lld\n",((y-x)/g*xx % (L/g) + (L/g))%(L/g));
	return 0;
}