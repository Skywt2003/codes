#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
const int maxn=305;
int n,a[maxn],p[maxn],to[maxn*maxn],f[2][maxn][maxn*maxn],cnt=0,ans,INF;
map <int,int> back;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline int gcd(int x,int y){
    if (y==0) return x;
    return gcd(y,x%y);
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++) p[i]=read();
    memset(f,63,sizeof(f));INF=f[0][0][0];
    cnt++;to[cnt]=0;back[0]=cnt;
    f[0][0][1]=0;
    for (int i=1;i<=n;i++)
    for (int j=0;j<=i;j++){
        int oldcnt=cnt;
        for (int k=1;k<=oldcnt;k++){
            if (f[1-(i&1)][j][k]<f[i&1][j][k]) f[i&1][j][k]=f[1-(i&1)][j][k];

            if (j==0||f[1-(i&1)][j-1][k]==INF) continue;
            int now=gcd(to[k],a[i]);
            if (back[now]==0) {cnt++;to[cnt]=now;back[now]=cnt;}
            int nowx=back[now];
            if (f[1-(i&1)][j-1][k]+p[i] < f[i&1][j][nowx]) f[i&1][j][nowx]=f[1-(i&1)][j-1][k]+p[i];
        }
    }
    ans=INF;int st=back[1];
    if (st) for (int i=1;i<=n;i++) if (f[n&1][i][st]<ans) ans=f[n&1][i][st];
    if (ans-INF) printf("%d\n",ans); else printf("-1\n");
    return 0;
}