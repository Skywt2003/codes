#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105,maxw=1005;
int n,allw,f[maxn][maxw],w[maxn],v[maxn],ans=0;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    allw=read();n=read();
    for (int i=1;i<=n;i++) w[i]=read(),v[i]=read();
    for (int i=1;i<=n;i++) 
        for (int j=allw;j>=0;j--){
            if(j>=w[i]) f[i][j]=max(f[i-1][j-w[i]]+v[i],f[i-1][j]); else f[i][j]=f[i-1][j];
            if (f[i][j]>ans) ans=f[i][j];
        }
    printf("%d\n",ans);
    return 0;
}