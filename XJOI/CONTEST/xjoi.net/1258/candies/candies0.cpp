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

const int INF=0x3f3f3f3f3f3f3f3f;

int T;
int n,k,a[maxn];

signed main(){
    T=read();
    while (T--){
        n=read();k=read();
        for (int i=1;i<=n;i++) a[i]=read();

        while (k--){
            int max_num=0,min_num=INF,k1,k2;
            for (int i=1;i<=n;i++) if (a[i]>max_num) max_num=a[i],k1=i;
            a[k1]--;
            for (int i=1;i<=n;i++) if (a[i]<min_num) min_num=a[i],k2=i;
            a[k2]++;
        }
        
        int max_num=0,min_num=INF;
        for (int i=1;i<=n;i++){
            if (a[i]>max_num) max_num=a[i];
            if (a[i]<min_num) min_num=a[i];
        }
        printf("%lld\n",max_num-min_num);
    }
    return 0;
}