#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=50005,maxk=1000005;

int T;
int n,k,sum[maxn];
int ans=0;

map<int,int> cnt;

signed main(){
    T=read();
    while (T--){
        cnt.clear(); ans=0; cnt[0]++;
        k=read(),n=read();
        for (int i=1;i<=n;i++){
            int x=read(); sum[i]=(x+sum[i-1])%k;
            ans+=cnt[sum[i]%k];
            cnt[sum[i]%k]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}