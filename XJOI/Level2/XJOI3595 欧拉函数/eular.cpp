#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int n,ans;
inline void Build_Phi(){
    long long x=n;ans=n;
    for (long long i=2;i<sqrt(n)&&x>1;i++) if (x%i==0){
        ans=ans/i*(i-1);
        while (x%i==0) x/=i;
    }
    if (x>1) ans=ans/x*(x-1);
}
int main(){
    scanf("%d",&n);
    Build_Phi();
    printf("%d\n",ans);
    return 0;
}