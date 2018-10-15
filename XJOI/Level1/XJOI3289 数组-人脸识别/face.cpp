#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=55;
int n,m,ans=0;
char a[maxn][maxn];
inline char read_ch(){
    char ch=getchar();
    while (ch<'a'||ch>'z') ch=getchar();
    return ch;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) a[i][j]=read_ch();
    for (int i=1;i<n;i++)
    for (int j=1;j<m;j++){
        bool ff=0,aa=0,cc=0,ee=0;
        if (a[i][j]=='f'||a[i+1][j]=='f'||a[i][j+1]=='f'||a[i+1][j+1]=='f') ff=1;
        if (a[i][j]=='a'||a[i+1][j]=='a'||a[i][j+1]=='a'||a[i+1][j+1]=='a') aa=1;
        if (a[i][j]=='c'||a[i+1][j]=='c'||a[i][j+1]=='c'||a[i+1][j+1]=='c') cc=1;
        if (a[i][j]=='e'||a[i+1][j]=='e'||a[i][j+1]=='e'||a[i+1][j+1]=='e') ee=1;
        if (ff&&aa&&cc&&ee) ans++;
    }
    printf("%d\n",ans);
    return 0;
}