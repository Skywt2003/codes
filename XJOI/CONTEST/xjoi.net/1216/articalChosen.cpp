#include<bits/stdc++.h>
using namespace std;

#define sqr(_) ((_)*(_))

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=105,maxt=2005;

struct pairs{
    int first,second,third;
};

int n,allv;
pair<int,int> a[maxn],c[maxn];
pairs b[maxn];
int na,nb,nc,ans=0;

int f[maxt];

pairs make_pairs(int x,int y,int z){
    pairs ret; ret.first=x; ret.second=y; ret.third=z;
    return ret;
}

signed main(){
    n=read();allv=read();
    for (int i=1;i<=n;i++){
        int kind=read();
        if (kind==1){
            int x=read(),y=read();
            a[++na]=make_pair(x,y);
        } else if (kind==2){
            int x=read(),y=read(),z=read();
            b[++nb]=make_pairs(x,y,z);
        } else if (kind==3){
            int x=read(),y=read();
            c[++nc]=make_pair(x,y);
        }
    }

    for (int i=1;i<=nc;i++)
    for (int j=c[i].second;j<=allv;j++)
        f[j]=max(f[j], f[j-c[i].second]+c[i].first);

    for (int i=1;i<=nb;i++)
    for (int k=1;k<=b[i].third;k++)
    for (int j=allv;j>=b[i].second;j--)
        f[j]=max(f[j], f[j-b[i].second]+b[i].first);

    for (int i=0;i<=allv;i++) ans=max(ans,f[i]);

    for (int i=1;i<=na;i++)
    for (int j=0;j<=allv;j++)
        ans=max(ans,f[j]+a[i].first*sqr(allv-j)-a[i].second*(allv-j));
    
    printf("%d\n",ans);
    return 0;
}