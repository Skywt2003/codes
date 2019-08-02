#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=205,maxq=50005;
const int INF=1<<30;

int n,e,q;
int lnk[maxn][maxn];
int t[maxn];

struct query{
    int x,y,t;
};
query b[maxq];

bool built[maxn];

signed main(){
    freopen("testdata.in","r",stdin);
    freopen("my.out","w",stdout);
    n=read();e=read();
    for (int i=0;i<n;i++) t[i]=read();
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i!=j) lnk[i][j]=INF;
    for (int i=0;i<e;i++){
        int x=read(),y=read(),z=read();
        lnk[x][y]=lnk[y][x]=min(lnk[x][y],z);
    }

    q=read();
    for (int i=0;i<q;i++) b[i].x=read(),b[i].y=read(),b[i].t=read();

    int k=-1;
    for (int ii=0;ii<q;ii++){
        while (k+1<n && t[k+1] <= b[ii].t){
            k++; built[k]=true;
            for (int i=0;i<n;i++) if (i!=k && lnk[i][k]!=INF)
                for (int j=0;j<n;j++) if (k!=j && i!=j && lnk[k][j]!=INF)
                    lnk[i][j]=min(lnk[i][j],lnk[i][k]+lnk[k][j]);
        }
        if (!built[b[ii].x] || !built[b[ii].y] || lnk[b[ii].x][b[ii].y]==INF) printf("-1\n");
        else printf("%d\n",lnk[b[ii].x][b[ii].y]);
    }
    return 0;
}