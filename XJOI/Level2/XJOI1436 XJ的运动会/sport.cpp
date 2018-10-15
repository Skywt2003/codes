#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10;
int n,m,a[maxn][maxn],slt[maxn],ans=0,maxx=0;
inline void DFS(int now,int cnt){
    if (cnt+2*(n-now)*maxx<ans) return;

    if (now==n){
        if (cnt>ans) ans=cnt;
        return;
    }

    DFS(now+1,cnt);

    for (int i=1;i<=m;i++) if (slt[i]<2){
        slt[i]++;
        DFS(now+1,cnt+a[now+1][i]);
        slt[i]--;
    }

    for (int i=1;i<=m;i++) if (slt[i]<2)
    for (int j=1;j<=m;j++) if (i-j&&slt[j]<2){
        slt[i]++;slt[j]++;
        DFS(now+1,cnt+a[now+1][i]+a[now+1][j]);
        slt[i]--;slt[j]--;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        scanf("%d",&a[i][j]);
        if (a[i][j]>maxx) maxx=a[i][j];
    }
    DFS(0,0);
    printf("%d\n",ans);
    return 0;
}