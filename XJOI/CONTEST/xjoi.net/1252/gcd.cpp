// C: gcd
#include <bits/stdc++.h>

using namespace std;
//#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=1e9+7;

int T,typ;

int gcd(int x,int y){
    if (x==0 || y==0) return 0;
    if (x<=y) return (gcd(y%x,x)+1)%tt; else return gcd(y,x);
}

signed main(){
    typ=read(),T=read();
    while (T--){
        int x=read(),y=read();
        int ans_max=0,ans_num=0;
        for (int i=1;i<=x;i++)
            for (int j=1;j<=y;j++)
                ans_max=max(ans_max,gcd(i,j));
        for (int i=1;i<=x;i++)
            for (int j=1;j<=y;j++)
                ans_num=(ans_num+(gcd(i,j)==ans_max))%tt;
        printf("%d %d\n",ans_max,ans_num);
    }
    return 0;
}
