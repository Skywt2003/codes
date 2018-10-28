#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=555;
int T,n,a,b,c,k1,k2,k3;
double p[50],A[maxn],B[maxn],p0;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void Build_Probability(){
    memset(p,0,sizeof(p));
    for (int i=1;i<=k1;i++)
    for (int j=1;j<=k2;j++)
    for (int k=1;k<=k3;k++)
        if (i!=a||j!=b||k!=c) p[i+j+k]+=p0;
}
int main(){
    T=read();
    while (T--){
        n=read();k1=read();k2=read();k3=read();a=read();b=read();c=read();
        p0=1.0/(double)k1/(double)k2/(double)k3;
        Build_Probability();
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        for (int i=n;i>=0;i--){
            for (int j=1;j<=k1+k2+k3;j++){
                A[i]+=(double)A[i+j]*p[j];
                B[i]+=(double)B[i+j]*p[j];
            }
            A[i]+=p0;B[i]+=1.0;
        }
        printf("%.16lf\n",(double)B[0]/(1.0-A[0]));
    }
    return 0;
}
