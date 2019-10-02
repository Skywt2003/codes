#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;

int n;
char a[maxn];
bool vis[15];

signed main(){
    n=read();
    scanf("%s",a+1);
    for (int i=1;i<=n;i++){
        if (a[i]=='L'){
            for (int i=0;i<=9;i++) if (!vis[i]) {vis[i]=true;break;}
        } else if (a[i]=='R'){
            for (int i=9;i>=0;i--) if (!vis[i]) {vis[i]=true;break;}
        } else vis[a[i]-'0']=false;
    }
    for (int i=0;i<=9;i++) putchar(vis[i]?'1':'0'); printf("\n");
    return 0;
}