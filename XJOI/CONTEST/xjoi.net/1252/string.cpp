// A: string
#include <bits/stdc++.h>

using namespace std;
//#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=3000005;

char s[maxn],now1[maxn],now2[maxn];
int n,q;

void make_answer(int x,int y){
    int len=y-x+1;
    int cnt1=0,cnt2=0;
    for (int i=x;i<=y;i++) if (i&1) now1[++cnt1]=s[i]; else now2[++cnt2]=s[i];
    for (int i=n-len;i>=y+1;i--) s[i+len]=s[i];
    for (int i=y+1;i<=y+len;i++) s[i]=(i-y<=cnt1)?now1[i-y]:now2[i-y-cnt1];
}

signed main() {
    scanf("%s",s+1);
    n=read();q=read();
    while (q--){
        int x=read(),y=read();
        if (y>=n) continue;
        make_answer(x,y);
    }
    for (int i=1;i<=n;i++) putchar(s[i]);
    return 0;
}
