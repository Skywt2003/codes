#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=150;
int a,b,c,INF,dst[maxn][maxn][maxn];
inline void DFS(int x,int y,int z,int s){
    if (dst[x][y][z]<s) return;
    dst[x][y][z]=s;
    if ((x==0&&y==z)||(y==0&&x==z)||(z==0&&x==y)){
        return;
    }

    int mm;
    mm=min(x,b-y);DFS(x-mm,y+mm,z,s+1); // x => y
    mm=min(y,c-z);DFS(x,y-mm,z+mm,s+1); // y => z
    mm=min(z,a-x);DFS(x+mm,y,z-mm,s+1); // z => x

    mm=min(a-x,y);DFS(x+mm,y-mm,z,s+1); // y => x
    mm=min(b-y,z);DFS(x,y+mm,z-mm,s+1); // z => y
    mm=min(c-z,x);DFS(x-mm,y,z+mm,s+1); // x => z
}
int main(){
    memset(dst,63,sizeof(dst));INF=dst[0][0][0];
    scanf("%d%d%d",&a,&b,&c);
    if (a&1){printf("NO\n");return 0;}
    dst[a][0][0]=0;
    DFS(a,0,0,0);
    int xx=a/2,ans=1<<30;
    if (dst[0][xx][xx]<ans) ans=dst[0][xx][xx];
    if (dst[xx][0][xx]<ans) ans=dst[xx][0][xx];
    if (dst[xx][xx][0]<ans) ans=dst[xx][xx][0];
    if (ans==INF) printf("NO\n"); else printf("%d\n",ans);
    return 0;
}