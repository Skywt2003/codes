#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,a[maxn];
long long m,sum=0;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline long long llmin(long long x,long long y){
    if (x<y) return x; else return y;
}
inline long long llmax(long long x,long long y){
    if (x>y) return x; else return y;
}
int main(){
    n=read();scanf("%lld",&m);
    for (int i=1;i<=n;i++){
        a[i]=read();
        sum+=(long long)a[i];
    }
    for (int i=1;i<=n;i++){ // [ 0 , sum-a[i] ] +x => m
        printf("%lld ",a[i]-((long long)llmin((long long)a[i],m-n+1)-llmax(m-sum+a[i],1)+1));
    }
    printf("\n");
    return 0;
}