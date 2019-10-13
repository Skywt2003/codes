#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n,p,w,d;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y),t=x;
    x=y; y=t-a/b*y;
    return r;
}

signed main(){
    n=read(); p=read(); w=read(); d=read();
    int g=gcd(w,d);
    if (p%g != 0) {printf("-1\n");return 0;}
    int x=-1,y=-1;
    int w1=w/g,d1=d/g,p1=p/g;
    exgcd(w1,d1,x,y);
    x*=p1; y*=p1;

    if (d/g != w/g){
        if ((d/g-w/g)>0){
            double kk=(double)(n-x-y)/(d/g-w/g);
            if (kk<0) kk-=1.0+1e-6;
            int k=(int)kk;
            if (k<0) x+=k*d/g,y-=k*w/g;
        } else {
            double kk=(double)(n-x-y)/(d/g-w/g);
            if (kk>0) kk+=1.0+1e-6;
            int k=(int)kk;
            if (k>0) x+=k*d/g,y-=k*w/g;
        }
    }
    int z=n-x-y;
    if (z<0 || x<0 || y<0) printf("-1\n"); else printf("%lld %lld %lld\n",x,y,z);
    return 0;
}