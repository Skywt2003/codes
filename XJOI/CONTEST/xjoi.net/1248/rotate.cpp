#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=105;

int T,n,m;
int a[maxn][maxn];

char read_ch(){
    char ch=getchar();
    while (ch!='x'&&ch!='o') ch=getchar();
    return ch;
}

int cnt=0;
pair<int,int> b[maxn*maxn],p[maxn*maxn];
bool vis[maxn*maxn];

bool DFS(int now,int lst){
    if (now==cnt){
        return true;
    }
    for (int i=1;i<=cnt;i++) if (!vis[i]){
        if ((lst && (now==0||b[i].second==p[now].second)) || ((!lst) && (now==0||b[i].first==p[now].first))){
            p[now+1]=b[i];
            vis[i]=true;
            if (DFS(now+1,1-lst)) return true;
            vis[i]=false;
        }
    }
    return false;
}

signed main(){
    T=read();
    while (T--){
        cnt=0;
        memset(vis,0,sizeof(vis));
        n=read();m=read();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++){
                a[i][j]=read_ch();
                if (a[i][j]=='o') b[++cnt]=make_pair(i,j);
            }
        
        bool ans=DFS(0,0)||DFS(0,1);
        printf(ans?"Possible\n":"Impossible\n");
    }
    return 0;
}