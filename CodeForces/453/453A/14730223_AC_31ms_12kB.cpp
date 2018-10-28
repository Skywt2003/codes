#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m;
double ans=0.0;
inline double qsm(double a,int b){
    double ret=1.0,w=a;
    while (b){
        if (b&1) ret=ret*w;
        b>>=1;w=w*w;
    }
    return ret;
}
int main(){
    scanf("%d%d",&m,&n);
    ans=(double)m;
    for (int i=1;i<m;i++) ans=ans-qsm(1.0-(double)i/m,n);
    printf("%.10f\n",ans);
    return 0;
}
