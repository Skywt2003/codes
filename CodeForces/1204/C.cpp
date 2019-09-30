#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f;

const int maxn=105;
const int maxm=1e6+5;

int n,m;
int dist[maxn][maxn];

int p[maxm];
vector<int> ans;

void Floyd(){
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

signed main(){
    n=read();
    memset(dist,0x3f,sizeof(dist));
    for (int i=1;i<=n;i++) dist[i][i]=0;
    
    char ch=getchar(); while (ch!='0'&&ch!='1') ch=getchar();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            if (ch=='1') dist[i][j]=1;
            if (i==n&&j==n) continue;
            ch=getchar(); while (ch!='0'&&ch!='1') ch=getchar();
        }
    m=read();
    for (int i=1;i<=m;i++) p[i]=read();

    Floyd();
    int last,cnt;
    for (int i=1;i<=m;i++){
        cnt++;
        if (i==1) {
            ans.push_back(p[i]);last=p[i];cnt=0;
        } else if (i!=2 && dist[last][p[i]] < cnt){
            ans.push_back(p[i-1]);
            last=p[i-1];cnt=1;
        }
    }
    ans.push_back(p[m]);
    printf("%d\n",(int)ans.size());
    for (int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}