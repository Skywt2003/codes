#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n,m;
double p;
inline double qsm(double a,int b){
    double ret=1.0,w=a;
    while (b){
        if (b&1) ret=ret*w;
        b>>=1;w=w*w;
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    p=qsm(((double)n-1.0)/(double)n,m);
    printf("%.10f\n",(double)n-(double)n*p);
    return 0;
}
