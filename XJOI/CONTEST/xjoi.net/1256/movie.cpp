#include<bits/stdc++.h>
using namespace std;

// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f;

const int maxn=205;

int n,k;
int a[maxn];

bool vis[maxn][maxn];

int mabs(int x){
    return (x>0)?x:-x;
}

int ans1,ans2,ans3,ans_min=0;

signed main(){
    n=read(); k=read();
    for (int i=1;i<=n;i++) a[i]=read();

    int xc=(k+1)/2,yc=(k+1)/2;

    for (int i=1;i<=n;i++){
        ans_min=INF; ans1=-1;
        for (int j=1;j<=k;j++){
            int cnt=0,sum=0;
            for (int t=1;t<=a[i];t++) cnt+=vis[j][t],sum+=mabs(j-xc)+mabs(t-yc);
            for (int t=1;t<=k-a[i]+1;t++){
                if (cnt==0 && sum<ans_min) ans_min=sum,ans1=j,ans2=t,ans3=t+a[i]-1;
                cnt-=vis[j][t]; sum-=mabs(j-xc)+mabs(t-yc);
                cnt+=vis[j][t+a[i]]; sum+=mabs(j-xc)+mabs(t+a[i]-yc);
            }
        }
        if (ans1==-1){
            printf("-1\n");
        } else {
            printf("%d %d %d\n",ans1,ans2,ans3);
            for (int j=ans2;j<=ans3;j++) vis[ans1][j]=true;
        }
    }
    return 0;
}