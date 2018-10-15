#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=15;
int n,f[maxn],ans=0,len;
inline void DFS(int x){
    if (x==len+1){
        int num=0;
        for (int i=1;i<=len;i++) num=num*10+f[i];
        if (num<=n) ans++;
        return;
    }
    f[x]=0;DFS(x+1);
    f[x]=1;DFS(x+1);
}
int main(){
    scanf("%d",&n);
    len=log10(n)+1;
    DFS(1);
    printf("%d\n",ans-1);
    return 0;
}