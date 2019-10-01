#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;
int n,a[maxn],ans=0;
int num1=0,numn1=0,num0=0;

signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
        if (a[i]==0) num0++; else
        if (a[i]>0) num1++,ans+=a[i]-1; else
        if (a[i]<0) numn1++,ans+=-1-a[i];
    }
    if (numn1&1){
        if (num0){
            ans+=num0;
        } else {
            ans+=2;
        }
    } else {
        ans+=num0;
    }
    printf("%lld\n",ans);
    return 0;
}