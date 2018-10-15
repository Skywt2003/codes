#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
long long a,b;;
inline long long gcd(long long x,long long y){
    if (y==0) return x;
    return gcd(y,x%y);
}
int main(){
    scanf("%d",&n);
    a=(long long)4*n;b=(long long)n+1;
    long long now=gcd(a,b);
    printf("%lld\n",a/now+1);
    return 0;
}