#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,a[maxn],sum[maxn],ans=-(1<<30);
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
    int lst_min=0;
    for (int i=1;i<=n;i++){
        if (sum[i]-lst_min>ans) ans=sum[i]-lst_min;
        if (sum[i]<lst_min) lst_min=sum[i];
    }
    printf("%d\n",ans);
    return 0;
}