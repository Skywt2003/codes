// #include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<iostream>

#define int long long

// using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=998244353;
const int maxn=1e7+5,N=1e7;

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

int id;
int x1,x2,x3,x4,x5,x6;
int y1,y2,y3,y4,y5,y6;

int fac[maxn];

void prebuild(){
	fac[0]=1;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%tt;
}

int inv(int x){
	return qsm(x,tt-2);
}

int C(int x,int y){
	if (x<y) return 0;
	return fac[x]*inv(fac[y])%tt*inv(fac[x-y])%tt;
}

namespace subtask0{
	signed main(){
		int x=x5-x1,y=y5-y1;
		int n=x3-x1,m=y3-y1;
		printf("%lld\n",(C(x+y,y)-C(n+m,m)*C(x+y-n-m,x-n)%tt+tt)%tt);
		return 0;
	}
}

namespace subtask1and2{
	int work(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
		int all=C(x4-x1+y4-y1,x4-x1);
		int sub=C(x2-x1+y2-y1,x2-x1) * C(x3-x2+y3-y2,x3-x2)%tt * C(x4-x3+y4-y3,x4-x3)%tt;
		return (all-sub+tt)%tt;
	}

	signed main(){
		int ans=0;
		for (int i=x3,j=y3;i<=x4;i++)
			for (int k=i,t=y4;k<=x4;k++)
				ans=(ans+work(x1,y1,i,j,k,t,x5,y5))%tt;
		for (int i=x3,j=y3;i<=x4;i++)
			for (int k=x4,t=j;t<=y4;t++)
				ans=(ans+work(x1,y1,i,j,k,t,x5,y5))%tt;
		for (int i=x3,j=y3;j<=y4;j++)
			for (int k=i,t=y4;k<=x4;k++)
				ans=(ans+work(x1,y1,i,j,k,t,x5,y5))%tt;
		for (int i=x3,j=y3;j<=y4;j++)
			for (int k=x4,t=j;t<=y4;t++)
				ans=(ans+work(x1,y1,i,j,k,t,x5,y5))%tt;

		printf("%lld\n",ans);
		return 0;
	}
}

namespace subtaskOther{
	signed main(){
		printf("FUCK YOU\n");
		return 0;
	}
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif

	id=read();
	x1=read(),x2=read(),x3=read(),x4=read(),x5=read(),x6=read();
	y1=read(),y2=read(),y3=read(),y4=read(),y5=read(),y6=read();

	prebuild();

	if (id==0) return subtask0::main(); else
	if (id==1 || id==2) return subtask1and2::main(); else
	return subtaskOther::main();
}