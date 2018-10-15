#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const long long p=1000000007,cnt=1000000006;
int n;
long long f[2];
inline long long qsm(long long a,long long b){
    long long ret=1,w=a;
    while (b){
        if (b&1) ret=((long long)ret*w)%p;
        b>>=1;w=((long long)w*w)%p;
    }
    return ret;
}
int main(){
    scanf("%d",&n);n--;
    f[0]=1;
    for (int i=1;i<=n;i++){
        long long a=(long long)(4*i+2)*f[1-(i&1)],b=(long long)(i+2);
        long long x=qsm(b,cnt-1);
        f[i&1]=((a%p)*(x%p))%p;
    }
    printf("%lld\n",f[n&1]);
    return 0;
}