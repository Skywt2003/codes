#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
int n,m,a[maxn][maxn];
bool vis[maxn];
inline int read_sig(){
    char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    return ch-'0';
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) a[i][j]=read_sig();
    for (int i=1;i<=m;i++){
        int mx=0;
        for (int j=1;j<=n;j++) if (a[j][i]>mx) mx=a[j][i];
        for (int j=1;j<=n;j++) if (a[j][i]==mx) vis[j]=1;
    }
    int sum=0;
    for (int i=1;i<=n;i++) sum+=vis[i];
    printf("%d\n",sum);
    return 0;
}