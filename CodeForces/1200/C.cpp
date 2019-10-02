#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n,m,q;

int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

signed main(){
    n=read(); m=read(); q=read();
    int d=gcd(n,m);
    while (q--){
        int x1=read(),y1=read(),x2=read(),y2=read();
        int p1=(y1-1)/(((x1==1)?n:m)/d),p2=(y2-1)/(((x2==1)?n:m)/d);
        printf((p1==p2)?"YES\n":"NO\n");
    }
    return 0;
}