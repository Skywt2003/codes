#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=35;
int n;
long long c[maxn];
inline void Build(){
    c[0]=1;
    for (int i=1;i<=30;i++){
        for (int j=0;j<i;j++) c[i]+=c[j]*c[i-j-1];
    }
}
int main(){
    Build();
    scanf("%d",&n);
    while (n!=0){
        printf("%lld\n",c[n]);
        scanf("%d",&n);
    }
    return 0;
}
