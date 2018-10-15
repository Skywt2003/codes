#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=35,maxk=905;
int n,k;
__int128 ans;
inline __int128 js(int x){
    __int128 ret=1;
    for (int i=2;i<=x;i++) ret=ret*(__int128)i;
    return ret;
}
inline void write(__int128 x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main(){
    scanf("%d%d",&n,&k);
    if (k>n){printf("0\n");return 0;}
    ans=js(n)/js(n-k);
    ans=ans*ans/js(k);
    write(ans);
    return 0;
}