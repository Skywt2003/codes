#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105,maxw=200005,add=100000;
int n,a[maxn];
bool vis[maxw],lstvis[maxw];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    vis[add]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=maxw;j++) lstvis[j]=vis[j];
        memset(vis,0,sizeof(vis));
        for (int j=maxw-4-a[i];j>=0;j--) vis[j]|=lstvis[j+a[i]];
        for (int j=a[i];j<=maxw-4;j++) vis[j]|=lstvis[j-a[i]];
    }
    if (vis[add]) {printf("0\n");return 0;}
    int x=add-1,y=add+1;
    while ((!vis[y])&&y<maxw) y++;
    while ((!vis[x])&&x>0) x--;
    printf("%d\n",min(add-x,y-add));
    return 0;
}