#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;

int n,cnt=0,p1,p2;
int a[maxn*2];

signed main(){
    n=read();
    if ((n&1)==false){
        printf("NO\n");
        return 0;
    }
    p1=1,p2=n+1;
    for (int i=1;i<=n;i++){
        a[p1]=++cnt; a[p2]=++cnt;
        p1++;p2++;swap(p1,p2);
    }
    printf("YES\n");
    for (int i=1;i<=2*n;i++) printf("%lld ",a[i]);
    printf("\n");
    return 0;
}