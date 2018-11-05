#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn=456789+10;

int n,a[maxn];

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    int xor_sum[maxn];
    for (int i=1;i<=n;i++){
        for (int j=i;j>=1;j--) xor_sum[j]=xor_sum[j+1]^a[j];
        int ans=0;
        int xor_f=0;
        for (int j=0;j<=i;j++) ans=max(ans,xor_f+xor_sum[j+1]),xor_f^=a[j+1];
        printf("%d\n",ans);
    }
    return 0;
}