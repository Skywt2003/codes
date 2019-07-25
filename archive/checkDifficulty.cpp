#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxm=35,maxt=1005;

int m,t,n;
double p[maxt][maxm];
double f[maxt][maxm][maxm];
double s[maxt][maxm];
double p1,p2;

signed main(){
    for (;;){
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        m=read();t=read();n=read();
        if (n==0 && m==0 && t==0) return 0;
        for (int i=1;i<=t;i++)
            for (int j=1;j<=m;j++)
                scanf("%lf",&p[i][j]);
        for (int i=1;i<=t;i++){
            f[i][0][0]=1.0;
            for (int j=1;j<=m;j++) f[i][j][0]=f[i][j-1][0]*(1-p[i][j]);
            for (int j=1;j<=m;j++)
                for (int k=1;k<=j;k++)
                    f[i][j][k]=f[i][j-1][k]*(1.0-p[i][j])+f[i][j-1][k-1]*p[i][j];
        }
        for (int i=1;i<=t;i++)
        for (int j=0;j<=m;j++)
        for (int k=0;k<=j;k++)
            s[i][j]+=f[i][m][k];
        p1=p2=1.0;
        for (int i=1;i<=t;i++) p1*=(1-s[i][0]),p2*=(s[i][n-1]-s[i][0]);
        
        printf("%.3lf\n",p1-p2);
    }
    return 0;
}