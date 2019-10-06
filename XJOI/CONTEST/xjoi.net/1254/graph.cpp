#include <bits/stdc++.h>

using namespace std;
//#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=998244353;
const int maxn=105;

int n,m,ans=0;
bool edge[maxn][maxn];
int clr[maxn];

void build_graph(){
    while (true){
        int modify_tag=0;
        for (int x=1;x<=n;x++)
            for (int y=x+1;y<=n;y++)
                for (int z=y+1;z<=n;z++)
                    if (edge[x][y] && edge[x][z] && edge[y][z]==false){
                        edge[y][z]=edge[z][y]=true;
                        modify_tag=1;
                    }
        if (modify_tag==0) break;
    }
}

void DFS(int x){
    if (x==n){
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (i!=j && edge[i][j] && clr[i]==clr[j]) return;
        ans=(ans+1)%tt;
        return;
    }
    for (int i=1;i<=n;i++){
        clr[x+1]=i;
        DFS(x+1);
    }
}

signed main(){
    n=read(); m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        edge[x][y]=edge[y][x]=true;
    }
    build_graph();

    DFS(0);

    printf("%d\n",ans);
    return 0;
}
