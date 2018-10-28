#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005,maxx=1000005;
int n,a[maxn],ans=0;
bool vis[1<<20];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
        int x=0;
        if (!vis[a[i]]) {vis[a[i]]=1;ans++;}
        for (int j=i-1;j>=1;j--){
            x=x|a[j];
            if (vis[x|a[i]]==0) {ans++;vis[x|a[i]]=1;}
            if ((x|a[i])==x) break;
        }
    }
    printf("%d\n",ans);
    return 0;
}