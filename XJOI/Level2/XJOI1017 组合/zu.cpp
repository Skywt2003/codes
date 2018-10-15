#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=15;
int n,m,a[maxn];
inline void DFS(int x,int k){
    if (k==m){
        for (int i=1;i<=k;i++) printf("%d ",a[i]);
        printf("\n");
        return;
    }
    if (x==n) return;
    for (int i=x+1;i<=n;i++){
        a[k+1]=i;
        DFS(i,k+1);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    DFS(0,0);
    return 0;
}