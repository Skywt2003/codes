#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,a[maxn],f[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++)
    for (int j=0;j<i;j++) if (a[j]<a[i]) f[i]=max(f[i],f[j]+1);
    int ans=0;
    for (int i=1;i<=n;i++) if (f[i]>ans) ans=f[i];
    printf("%d\n",ans);
    return 0;
}