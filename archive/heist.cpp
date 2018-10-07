#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,a[maxn];
long long ans=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=2;i<=n;i++) ans+=(long long)a[i]-a[i-1]-1;
	cout<<ans<<endl;
	return 0;
}