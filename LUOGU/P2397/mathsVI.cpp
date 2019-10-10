#include<bits/stdc++.h>
using namespace std;

// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxd=35;

int n,a[maxd][2];

signed main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        for (int j=0;j<31;j++) a[j][(x&(1<<j))!=0]++;
    }
    int ans=0;
    for  (int i=0;i<31;i++) ans+=(a[i][1]>a[i][0])<<i;
    printf("%d\n",ans);
    return 0;
}