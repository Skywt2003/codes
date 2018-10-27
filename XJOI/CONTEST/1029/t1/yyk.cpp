#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=55,maxv=2550,V=2500;

int a,b,c,d;
double p1[maxv],p2[maxv];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	a=read(),b=read(),c=read(),d=read();
	
	for (int i=1;i<=b;i++) p1[i]=1.0/b;
	for (int i=2;i<=a;i++){
		for (int j=V;j>=0;j--){
			p1[j]=0;
			for (int k=1;k<=b && j-k>=0;k++) p1[j]+=p1[j-k]/b;
		}
	}

	for (int i=1;i<=d;i++) p2[i]=1.0/d;
	for (int i=2;i<=c;i++){
		for (int j=V;j>=0;j--){
			p2[j]=0;
			for (int k=1;k<=d && j-k>=0;k++) p2[j]+=p2[j-k]/d;
		}
	}

	for (int i=1;i<=V;i++) p2[i]+=p2[i-1];

	double ans=0.0,sc=0.0;
	for (int i=1;i<=V;i++) ans+=p1[i]*p2[i-1],sc+=p1[i]*p2[i-1]*(double)i;
	if (ans==0.0) printf("-1.0\n"); else printf("%.15lf\n",sc/ans);
	return 0;
}