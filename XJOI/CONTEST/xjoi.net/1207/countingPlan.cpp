#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=35,maxs=65536+5;
const int tt=1000000007;
int n,p,c;
int a[maxn];
map<int,int> cnt,tmp;
map<int,int>::iterator it;

signed main(){
    n=read();p=read();c=read();
    for (int i=1;i<=n;i++) a[i]=read()%p;

    for (int i=1;i<=n;i++){
        tmp=cnt;
        for (it=tmp.begin();it!=tmp.end();it++){
            cnt[a[i]*(it->first)%p]=(cnt[a[i]*(it->first)%p]+it->second)%tt;
        }
        cnt[a[i]]++;
    }
    printf("%lld\n",cnt[c]);
    return 0;
}