#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10005;
int n,a[maxn],sum[maxn];
long long ans=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int now=0,cnt=1;
	while (now<=n){
		now+=1<<cnt;
		ans+=cnt*(sum[min(now,n)]-sum[now-(1<<cnt)]);
		cnt++;
	}
	printf("%lld\n",ans);
	return 0;
}
