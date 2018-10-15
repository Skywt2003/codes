#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int n;
long long cnt=0;
int main(){
    scanf("%d",&n);
    int s=sqrt(n);
    for (int i=2;i<=s;i++){
        int x=n/i;
        cnt+=(x-1)*i;
        if (x>s) cnt+=(long long)(s+x+1)*(x-s)/2;
    }
    printf("%lld\n",cnt);
    return 0;
}