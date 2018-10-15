#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=50005;
int n,m,a[maxn];
long long sum[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum[i]=(long long)sum[i-1]+(long long)a[i];
	for (int i=1;i<=m;i++){
		int w,lft,rght,c;
		w=read();lft=read();rght=read();c=read();
		printf("%lld\n",sum[rght]-sum[lft-1]);
	}
	return 0;
}
