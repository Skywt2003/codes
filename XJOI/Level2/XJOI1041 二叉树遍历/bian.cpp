#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
int n,ls[maxn],rs[maxn],fa[maxn];
inline void DFS1(int x){
    printf("%d ",x);
    if (ls[x]) DFS1(ls[x]);
    if (rs[x]) DFS1(rs[x]);
}
inline void DFS2(int x){
    if (ls[x]) DFS2(ls[x]);
    printf("%d ",x);
    if (rs[x]) DFS2(rs[x]);
}
inline void DFS3(int x){
    if (ls[x]) DFS3(ls[x]);
    if (rs[x]) DFS3(rs[x]);
    printf("%d ",x);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x,l,r;
        scanf("%d%d%d",&x,&l,&r);
        ls[x]=l;rs[x]=r;fa[l]=fa[r]=x;
    }
    int s=0;
    for (int i=1;i<=n;i++) if (~fa[i]) {s=i;break;} 
    DFS1(s);printf("\n");
    DFS2(s);printf("\n");
    DFS3(s);printf("\n");
    return 0;
}