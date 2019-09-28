#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005;

int n;
char s[maxn],t[maxn];
int cnt1=0,cnt2=0;
int a[maxn],b[maxn];

signed main(){
    n=read();
    scanf("%s",s+1);
    scanf("%s",t+1);
    for (int i=1;i<=n;i++) if (s[i]!=t[i]){
        if (s[i]=='a' && t[i]=='b') a[++cnt1]=i; else b[++cnt2]=i;
    }
    if ((cnt1+cnt2)&1){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",cnt1/2+cnt2/2+(((cnt1&1)&&(cnt2&1))?2:0));
    for (int i=1;i<=cnt1-1;i+=2) printf("%d %d\n",a[i],a[i+1]);
    for (int i=1;i<=cnt2-1;i+=2) printf("%d %d\n",b[i],b[i+1]);
    if ((cnt1&1)&&(cnt2&1)){
        printf("%d %d\n",a[cnt1],a[cnt1]);
        printf("%d %d\n",a[cnt1],b[cnt2]);
    }
    return 0;
}