#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005;

int n,m,typ;
int a[maxn];
int last_ans=0;

signed main(){
    n=read(); m=read(); typ=read();
    while (m--){
        int opt=read();
        if (opt==0){
            int x=read(),y=read(),delta=read();
            if (typ) x^=last_ans,y^=last_ans,delta^=last_ans;
            for (int i=x;i<=y;i++) a[i]+=delta;
        } else if (opt==1){
            int x=read(),y=read();
            if (typ) x^=last_ans,y^=last_ans;
            for (int i=1;i<=(y-x+1)/2;i++) swap(a[x+i-1],a[y-i+1]);
        } else if (opt==2){
            int x=read(),y=read(),sum=0;
            if (typ) x^=last_ans,y^=last_ans;
            for (int i=x;i<=y;i++) sum+=a[i];
            printf("%lld\n",sum); last_ans=sum;
        }
    }
    return 0;
}