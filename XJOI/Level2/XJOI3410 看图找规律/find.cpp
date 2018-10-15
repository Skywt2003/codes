#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
long long n,x,xf;
int main(){
    scanf("%lld",&n);
    x=(long long)sqrt(n-1);
    xf=x*x;x++;
    if (x&1){
        if (xf+1<=n&&n<=xf+x) printf("%lld %lld\n",x,n-xf); else printf("%lld %lld\n",x*x-n+1,x);
    } else{
        if (xf+1<=n&&n<=xf+x) printf("%lld %lld\n",n-xf,x); else printf("%lld %lld\n",x,x*x-n+1); 
    }
    return 0;
}