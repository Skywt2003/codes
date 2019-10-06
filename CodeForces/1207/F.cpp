#include <bits/stdc++.h>

using namespace std;
//#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=500005;
const int N=500000;

int q;
int a[maxn];
int f[705][705];

signed main() {
    q=read();
    while (q--){
        int opt=read(),x=read(),y=read();
        if (opt==1){
            a[x]+=y;
            for (int i=1;i<=700;i++) f[i][x%i]+=y;
        } else {
            if (x<=700) printf("%d\n",f[x][y]); else {
                int ans=0;
                for (int i=y;i<=N;i+=x) ans+=a[i];
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
