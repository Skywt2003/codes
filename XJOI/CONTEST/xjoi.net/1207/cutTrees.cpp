#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;

int n;
pair<int,int> a[maxn];
int ans=0;

bool cmp(pair<int,int> aa,pair<int,int> bb){
    return aa.first < bb.first;
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read(),y=read();
        a[i]=make_pair(x,y);
    }
    sort(a+1,a+1+n);

    int tmp=-1;
    for (int i=1;i<=n;i++){
        if (a[i+1].first==a[i].first) tmp=a[i].first,ans+=a[i].second,a[i].second=0;
        if (a[i].first==tmp) ans+=a[i].second,a[i].second=0; else tmp=-1;
    }

    for (int i=2;i<=n;i++){
        int now=a[i].first-a[i-1].first;
        if (a[i].second > now) ans+=a[i].second-now,a[i].second=now; 
    }

    for (int i=1;i<n;i++){
        int now=a[i+1].first-a[i].first;
        if (a[i].second > now) ans+=a[i].second-now,a[i].second=now; 
    }

    printf("%lld\n",ans);
    return 0;
}