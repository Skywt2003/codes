#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,f[maxn],len=0;
bool vis[maxn][maxn];
char a[maxn];
int main(){
    char ch=getchar();
    while (ch!=10&&ch!=13&&ch!=-1){a[++len]=ch;ch=getchar();}
    for (int i=0;i<=len;i++) vis[i][i]=1;
    for (int L=1;L<len;L++)
    for (int i=1;i<=len-L+1;i++){
        int j=i+L;
        if ((vis[i+1][j-1]||L==1)&&a[i]==a[j]) vis[i][j]=1;
    }
    memset(f,63,sizeof(f));
    f[0]=0;
    for (int i=1;i<=len;i++)
    for (int j=0;j<i;j++) if (vis[j+1][i]) f[i]=min(f[i],f[j]+1);
    printf("%d\n",f[len]);
    return 0;
}