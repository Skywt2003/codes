#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=20,maxm=105,maxs=32768+5;

int m,n,p[maxn];
int s[maxn];
double f[maxm][maxs];
int alls;

signed main(){
    m=read();n=read();
    alls=1<<n;
    for (int i=0;i<n;i++){
        p[i]=read();
        int x=read(); while (x) s[i]|=1<<(x-1),x=read();
    }
    for (int i=m;i>=1;i--){
        for (int j=0;j<alls;j++){
            for (int k=0;k<n;k++){
                if ((s[k]&j)==s[k]) f[i][j]+=max(f[i+1][j],f[i+1][j|(1<<k)]+(double)p[k])/n;
                else f[i][j]+=f[i+1][j]/n;
            }
        }
    }
    printf("%.6lf\n",f[1][0]);
    return 0;
}