#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int tt=1000000007;
int n,m;
inline int qsm(int a,int b){
    int ret=1,w=a%tt;
    while (b){
        if (b&1) ret=((long long)ret*w)%tt;
        w=((long long)w*w)%tt;
        b>>=1;
    }
    return ret;
}
int main(){
    scanf("%d%d",&m,&n);
    printf("%d",qsm(n,m));
    return 0;
}