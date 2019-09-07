#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int T,n,m;

int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

signed main(){
    T=read();
    while (T--){
        n=read();m=read();
        if (n>m) swap(n,m);
        printf("%lld\n",gcd(n-1,m-1)+1);
    }
    return 0;
}