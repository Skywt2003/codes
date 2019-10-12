#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=355,maxk=45;

int n,m,a[maxn];
int cnt[5];
int f[maxk][maxk][maxk][maxk];

signed main(){
    n=read(); m=read();
    for (int i=0;i<n;i++) a[i]=read();
    for (int i=0;i<m;i++) cnt[read()]++;

    f[0][0][0][0]=a[0];
    for (int i=0;i<=cnt[1];i++)
        for (int j=0;j<=cnt[2];j++)
            for (int k=0;k<=cnt[3];k++)
                for (int t=0;t<=cnt[4];t++){
                    if (i+1<=cnt[1]) f[i+1][j][k][t]=max(f[i+1][j][k][t],f[i][j][k][t]+a[(i+1)+2*j+3*k+4*t]);
                    if (j+1<=cnt[2]) f[i][j+1][k][t]=max(f[i][j+1][k][t],f[i][j][k][t]+a[i+2*(j+1)+3*k+4*t]);
                    if (k+1<=cnt[3]) f[i][j][k+1][t]=max(f[i][j][k+1][t],f[i][j][k][t]+a[i+2*j+3*(k+1)+4*t]);
                    if (t+1<=cnt[4]) f[i][j][k][t+1]=max(f[i][j][k][t+1],f[i][j][k][t]+a[i+2*j+3*k+4*(t+1)]);
                }
    printf("%d\n",f[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
    return 0;
}