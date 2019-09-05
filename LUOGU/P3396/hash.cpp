#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

inline char read_ch(){
    char ch=getchar();
    while (ch!='A' && ch!='C') ch=getchar();
    return ch;
}

const int maxn=150005,maxsize=405;
int n,m,size;
int value[maxn];
int f[maxsize][maxsize];

signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) value[i]=read();
    size=sqrt(n);

    for (int i=1;i<=n;i++)
        for (int p=1;p<=size;p++)
            f[p][i%p]+=value[i];

    while (m--){
        char ops=read_ch();
        if (ops=='A'){
            int x=read(),y=read();
            if (x>size){
                int ans=0;
                for (int i=y;i<=n;i+=x) ans+=value[i];
                printf("%lld\n",ans);
            } else printf("%lld\n",f[x][y]);
        } else {
            int x=read(),y=read();
            int tmp=value[x]; value[x]=y;
            for (int p=1;p<=size;p++) f[p][x%p]+=value[x]-tmp;
        }
    }
    return 0;
}