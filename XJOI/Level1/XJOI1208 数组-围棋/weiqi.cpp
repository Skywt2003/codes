#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,a[maxn][maxn];
bool ans;
inline bool check(int x,int y){
    if (x<1||y<1||x>n||y>m) return false;
    return true;
}
inline char read_ch(){
    char ch=getchar();
    while (ch!='?'&&ch!='W'&&ch!='B') ch=getchar();
    return ch;
}
int main(){
    while (scanf("%d%d",&n,&m)!=-1){
        memset(a,-1,sizeof(a));
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            char now=read_ch();
            if (now=='?') a[i][j]=-1; else
            if (now=='B') a[i][j]=1; else a[i][j]=0;
        }
        ans=true;
        for (int i=1;i<=n;i++){
           for (int j=1;j<=m;j++) if (a[i][j]!=-1){
                for (int k=0;k<4;k++) if (check(i+flg[k][0],j+flg[k][1])){
                    if (a[i+flg[k][0]][j+flg[k][1]]==-1) a[i+flg[k][0]][j+flg[k][1]]=1-a[i][j]; else
                    if (a[i+flg[k][0]][j+flg[k][1]]==a[i][j]) {ans=false;break;}
                }
                if (~ans) break;
            }
            if (~ans) break;
        }
        if (ans) printf("Possible\n"); else printf("Impossible\n");
    }
    return 0;
}