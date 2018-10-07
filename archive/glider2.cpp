#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200005;
int n,h;
long long ans=0;
long long sum[maxn];
struct fly{
	long long x,y;
}a[maxn];
int que[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	n=read();h=read();
	int tmp=0;
	for (int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		sum[i]=sum[i-1]+a[i].y-a[i].x;
	}
	a[n+1].x=(long long)1<<60;
	a[0].x=a[0].y=-((long long)1<<6);
	int j=0;
	for (int i=0;i<=n;i++){
		if (j<i) j=i;
		while (j+1<=n&&sum[j]-(i?sum[i-1]:0)+h+a[i].x > a[j+1].x) j++;
		ans=max((long long)ans,(long long)sum[j]-(i?sum[i-1]:0)+h);
	}
	cout<<ans;
	return 0;
}