#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=5005;
struct Bigint{
    int len,a[maxn];
    Bigint (){len=0;memset(a,0,sizeof(a));}
    Bigint operator +(Bigint b){
        Bigint c;
        memset(c.a,0,sizeof(c.a));
        c.len=max(len,b.len);
        for (int i=1;i<=c.len;i++){
            c.a[i]+=a[i]+b.a[i];
            c.a[i+1]+=c.a[i]/10;
            c.a[i]%=10;
        }
        if (c.a[c.len+1]) c.len++;
        return c;
    }
    void write(){
        for (int i=len;i>=1;i--) printf("%d",a[i]);
    }
}f[205];
int main(){
    int n;
    scanf("%d",&n);
    f[1].len=1;f[1].a[1]=1;
    f[2].len=1;f[2].a[1]=1;
    for (int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    f[n].write();
    return 0;
}