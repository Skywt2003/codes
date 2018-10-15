#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=15;
int n,ans;
bool h[maxn],w[maxn],d[maxn*2],u[maxn*2];
inline void DFS(int x){
    if (x==n) {ans++;return;}
    int i=x;
    for (int j=1;j<=n;j++) if ((!w[j])&&(!d[i-j+n])&&(!u[i+j-1])){
        h[i]=w[j]=d[i-j+n]=u[i+j-1]=1;
        DFS(x+1);
        h[i]=w[j]=d[i-j+n]=u[i+j-1]=0;
    }
}
int main(){
    scanf("%d",&n);
    DFS(0);
    printf("%d\n",ans);
    return 0;
}