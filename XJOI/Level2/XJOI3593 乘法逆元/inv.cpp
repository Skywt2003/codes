#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
long long a,p,cnt;
inline int gcd(int x,int y){
    if (y==0) return x;
    return gcd(y,x%y);
}
inline long long qsm(long long a,long long b){
    long long ret=1,w=a;
    while (b){
        if (b&1) ret=((long long)ret*w)%p;
        b>>=1;w=((long long)w*w)%p;
    }
    return ret;
}
inline void Build_Phi(){
    long long x=p;cnt=x;
    for (long long i=2;i<sqrt(p)&&x>1;i++) if (x%i==0){
        cnt=cnt/i*(i-1);
        while (x%i==0) x/=i;
    }
    if (x>1) cnt=cnt/x*(x-1);
}
int main(){
    scanf("%lld%lld",&a,&p);
    if (gcd(a,p)!=1){printf("-1\n");return 0;}
    Build_Phi();
    printf("%lld\n",qsm(a,cnt-1));
    return 0;
}
