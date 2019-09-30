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
char s[maxn];
bool vis[maxn];

signed main(){
    scanf("%s",s+1); n=strlen(s+1);
    for (int i=1;i<=n;i++) if (i!=1 && s[i-1]=='1' && s[i]=='0'){
        int l=i-1,r=i; vis[l]=vis[r]=true;
        while (l-1>=1&&s[l-1]=='1' && r+1<=n&&s[r+1]=='0') l--,r++,vis[l]=vis[r]=true;
        for (;;){
            if (l-1>=1 && vis[l-1]){
                while (l-1>=1 && vis[l-1]) l--;
                while (l-1>=1&&s[l-1]=='1' && r+1<=n&&s[r+1]=='0') l--,r++,vis[l]=vis[r]=true;
            } else break;
        }
        i=r;
    }
    for (int i=1;i<=n;i++) if ((!vis[i]) && s[i]=='1') s[i]='0';
    printf("%s\n",s+1);
    return 0;
}