#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=305,maxe=506;

int n,s=-1,t=-1;
int f[maxn];
bool lnk[maxn][maxn];
vector<int> ans;

int DFS(int x){
    for  (int i=1;i<=255;i++) if (lnk[x][i]){
        lnk[x][i]=lnk[i][x]=false;
        DFS(i);
    }
    ans.push_back(x);
}

namespace UFA{
    int fa[maxn];

    void init(int n){
        for (int i=1;i<=n;i++) fa[i]=i;
    }

    int getfa(int x){
        if (fa[x]==x) return x;
        fa[x]=getfa(fa[x]);
        return fa[x];
    }

    void merge(int x,int y){
        x=getfa(x),y=getfa(y);
        if (x==y) return;
        fa[x]=y;
    }
}

signed main(){
    n=read(); UFA::init(255);
    char ch=getchar();while ((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z')) ch=getchar();
    for (int i=1;i<=n;i++){
        char from=ch; ch=getchar();while ((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z')) ch=getchar();
        lnk[from][0]=lnk[ch][0]=true;
        lnk[from][ch]=lnk[ch][from]=true; f[from]++,f[ch]++;
        UFA::merge(from,ch);
        if (i==n) continue;
        ch=getchar();while ((ch<'a'||ch>'z')&&(ch<'A'||ch>'Z')) ch=getchar();
    }
    for (int i=1;i<=255;i++) if (lnk[i][0])
    for (int j=1;j<=255;j++) if (lnk[j][0]){
        if (UFA::getfa(i)!=UFA::getfa(j)){
            printf("No Solution\n");
            return 0;
        }
    }

    for (int i=1;i<=255;i++) if (f[i]&1){
        if (s==-1) s=i; else
        if (t==-1) t=i; else{
            printf("No Solution\n");
            return 0;
        }
    }
    if (s==-1) for (int i=1;i<=255;i++) if (f[i]) {s=i;break;}
    DFS(s);
    reverse(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++) printf("%c",ans[i]);
    printf("\n");
    return 0;
}