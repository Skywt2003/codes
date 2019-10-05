    // D
     
    #include <bits/stdc++.h>
     
    using namespace std;
    #define int long long
     
    inline int read(){
        int ret=0,f=1;char ch=getchar();
        while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
        while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
        return ret*f;
    }
     
    const int maxn=3e5+5;
    const int tt=998244353;
     
    int n;
    pair<int,int> a[maxn];
    int fact[maxn];
     
    bool compare_by_second(pair<int,int> aa,pair<int,int> bb){
        return aa.second < bb.second;
    }
    bool compare_by_double(pair<int,int> aa,pair<int,int> bb){
        return (aa.first < bb.first) || (aa.first == bb.first && aa.second < bb.second);
    }
     
    void build_fact(){
        fact[1]=1;
        for (int i=2;i<=n;i++) fact[i]=fact[i-1]*i%tt;
    }
     
    signed main() {
        n=read(); build_fact();
        for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=read();
     
        int ans=0,now=1;
        sort(a+1,a+1+n,compare_by_second);
        for (int i=1,j;i<=n;i=j+1){
            j=i;
            while (j+1<=n && a[j+1].second == a[i].second) j++;
            now=now*fact[j-i+1]%tt;
        }
        ans=(ans+now)%tt; now=1;
        sort(a+1,a+1+n,compare_by_double);
        for (int i=1,j;i<=n;i=j+1){
            j=i;
            while (j+1<=n && a[j+1].first == a[i].first) j++;
            now=now*fact[j-i+1]%tt;
        }
        ans=(ans+now)%tt;
        now=1;
        for (int i=1,j;i<=n;i=j+1){
            j=i;
            while (j+1<=n && a[j+1].first==a[i].first&&a[j+1].second==a[i].second) j++;
            if (a[j+1].first>a[i].first && a[j+1].second<a[i].second) {now=0;break;}
            now=now*fact[j-i+1]%tt;
        }
        ans=(ans-now+tt)%tt;
     
        printf("%lld\n",(fact[n]-ans+tt)%tt);
        return 0;
    }