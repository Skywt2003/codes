#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n,m,k,x;

int qsm(int a,int b){
    int ret=1,w=a%n;
    while (b){
        if (b&1) ret=ret*w%n;
        b>>=1; w=w*w%n;
    }
    return ret;
}

signed main(){
    n=read(); m=read(); k=read(); x=read();
    printf("%lld\n",(m*qsm(10,k)%n+x)%n);
    return 0;
}