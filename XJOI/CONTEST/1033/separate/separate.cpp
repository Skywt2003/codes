#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=2005,INF=0x3f3f3f3f3f3f3f3f;
int n,m,a[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();m=read();
	if (m==1) swap(n,m);
	for (int i=1;i<=m;i++) a[i]=read();
	int ans=INF;
	for (int i=2;i<=m;i++){
		int num1,num2;
		int min_num=INF,max_num=-INF;
		for (int j=1;j<i;j++) min_num=min(min_num,a[j]),max_num=max(max_num,a[j]);
		// printf("i=%lld, max_num=%lld, min_num=%lld\n",i,max_num,min_num);
		num1=max_num-min_num;
		min_num=INF;max_num=-INF;
		for (int j=i;j<=m;j++) min_num=min(min_num,a[j]),max_num=max(max_num,a[j]);
		// printf("i=%lld, max_num=%lld, min_num=%lld\n",i,max_num,min_num);
		num2=max_num-min_num;
		ans=min(ans,max(num1,num2));
	}
	printf("%lld\n",ans);
	return 0;
}