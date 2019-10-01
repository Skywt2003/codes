#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f;

const int maxn=105,maxx=205;

int n,m;
int a[maxn],b[maxn];
int ha[maxx],hb[maxx];

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read(),ha[a[i]]=1;
    m=read();
    for (int i=1;i<=m;i++) b[i]=read(),hb[b[i]]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            if (ha[a[i]+b[j]]==0 && hb[a[i]+b[j]]==0){
                cout<<a[i]<<" "<<b[j]<<endl;
                return 0;
            }
        }
    return 0;
}