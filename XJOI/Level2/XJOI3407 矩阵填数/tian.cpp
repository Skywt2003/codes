#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int tt=1000000007;
long long n,m;
int k;
inline long long qsm(int a,__int128 b){
    long long ret=1,w=(long long)a;
    while (b){
        if (b%2) ret=(ret*w)%tt;
        b/=2;w=(w*w)%tt;
    }
    return ret;
}
int main(){
    scanf("%lld%lld%d",&n,&m,&k);
    if ((n&1)-(m&1)&&(k==-1)){printf("0\n");return 0;}
    printf("%lld\n",qsm(2,(__int128)(n-1)*(__int128)(m-1)));
    return 0;
}