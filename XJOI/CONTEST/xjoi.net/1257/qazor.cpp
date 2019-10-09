#include<bits/stdc++.h>
#define int long long

#define sqr(_) ((_)*(_))

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=205,maxx=10005;
const int LIMIT=10000;

const double pi=3.14159265359;

struct circle{
    int x,y,r,R;
};
circle a[maxn];

int n;
int vis[maxn];
bool all_zero=true;

double ans=0.0;

signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        a[i].x=read(),a[i].y=read(),a[i].R=read(),a[i].r=read();
        if (a[i].x||a[i].y) all_zero=false;
    }
    if (n==1){
        printf("%.3lf\n",pi*(sqr(a[1].R)-sqr(a[1].r)));
    } else if (n==2){
        
    } else if (all_zero){
        for (int i=1;i<=n;i++){
            for (int j=a[i].r;j<=a[i].R;j++) vis[j]=1;
        }
        for (int i=0,j;i<=LIMIT;i=j+1){
            while (i<=LIMIT && (!vis[i])) i++;
            if (i>LIMIT) break;
            j=i;
            while (j+1<=LIMIT && vis[j+1]) j++;
            ans+=pi*(sqr(j)-sqr(i));
        }
        printf("%.3lf\n",ans);
    } else printf("0.000\n");
    return 0;
}