#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,nn=0,a[maxn],hsh[maxn];
long long f[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read(),hsh[a[i]]++,nn=max(a[i],nn);
    for (int i=2;i<=nn+1;i++){
        if (i-3>=0) f[i]=max(f[i-2]+(long long)hsh[i-1]*(i-1),f[i-3]+(long long)hsh[i-1]*(i-1));
        else f[i]=f[i-2]+(long long)hsh[i-1]*(i-1);
    }
    printf("%lld\n",max(f[nn+1],f[nn]));
    return 0;
}