#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,a,b,p;
inline int qsm(int a,int b){
    int ret=1,w=a%p;
    while (b){
        if (b&1) ret=((long long)ret*w)%p;
        b>>=1;w=((long long)w*w)%p;
    }
    return ret;
}
int main(){
    scanf("%d%d%d",&m,&n,&p);
    a=b=1;
    for (int i=2;i<=m;i++) a=((long long)a*(i%p))%p;
    for (int i=2;i<=n;i++) b=((long long)b*(i%p))%p;
    for (int i=2;i<=m-n;i++) b=((long long)b*(i%p))%p;
    int x=qsm(b,p-2);
    printf("%d\n",((long long)(a%p)*(x%p))%p);
    return 0;
}
