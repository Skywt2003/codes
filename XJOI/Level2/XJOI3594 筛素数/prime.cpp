#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10000005;
int n,prime[maxn];
bool flg[maxn];
int main(){
    scanf("%d",&n);
    memset(flg,1,sizeof(flg));
    flg[1]=false;
    for (int i=2;i<=n;i++){
        if (flg[i]) prime[++prime[0]]=i;
        for (int j=1;j<=prime[0];j++){
            if (i*prime[j]>n) break;
            flg[i*prime[j]]=false;
            if (i%prime[j]==0) break;
        }
    }
//  for (int i=1;i<=prime[0];i++) printf(" %d\n",prime[i]);
    printf("%d\n",prime[0]);
    return 0;
}
