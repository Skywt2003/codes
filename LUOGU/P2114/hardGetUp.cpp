#include<bits/stdc++.h>

// #define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1e5+5;

int n,m;

int a[maxn][35],opt[maxn]; // opt=0/1/2: OR/AND/XOR
int num=0,ans=0;

signed main(){
    n=read(); m=read();
    for (int i=1;i<=n;i++){
        char s[5]; scanf("%s",s+1);
        if (s[1]=='O') opt[i]=0; else
        if (s[1]=='A') opt[i]=1; else
        if (s[1]=='X') opt[i]=2;
        int x=read();
        for (int j=0;j<31;j++) if (x&(1<<j)) a[i][j]=1;
    }
    for (int j=30;j>=0;j--){
        int now=0;
        for (int i=1;i<=n;i++){
            if (opt[i]==0) now|=a[i][j]; else
            if (opt[i]==1) now&=a[i][j]; else
            if (opt[i]==2) now^=a[i][j];
        }
        if (now==1) {ans+=1<<j; continue;}
        now=1;
        for (int i=1;i<=n;i++){
            if (opt[i]==0) now|=a[i][j]; else
            if (opt[i]==1) now&=a[i][j]; else
            if (opt[i]==2) now^=a[i][j];
        }
        if (now==1 && num+(1<<j)<=m) {ans+=1<<j; num+=1<<j; continue;}
    }
    printf("%d\n",ans);
    return 0;
}