    #include <bits/stdc++.h>
     
    using namespace std;
    //#define int long long
     
    inline int read(){
        int ret=0,f=1;char ch=getchar();
        while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
        while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
        return ret*f;
    }
     
    int T;
    int a,b,c,d,e;
    int ans=0;
     
    signed main(){
        T=read();
        while (T--){
            ans=0;
            a=read(); b=read(); c=read();
            d=read(); e=read();
            if (d>e){
                int now=min(a/2,b);
                ans+=d*now; a-=2*now; b-=now;
                now=min(a/2,c);
                ans+=e*now; a-=2*now; c-=now;
            } else {
                int now=min(a/2,c);
                ans+=e*now; a-=2*now; c-=now;
                now=min(a/2,b);
                ans+=d*now; a-=2*now; b-=now;
            }
            printf("%d\n",ans);
        }
        return 0;
    }