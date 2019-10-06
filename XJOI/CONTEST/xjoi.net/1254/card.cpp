// XJOI 1254 A

#include <bits/stdc++.h>

using namespace std;
//#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005;

int n;
pair<int,int> a[maxn];
int b[maxn];
int ans[maxn];

bool compare_second(pair<int,int> aa,pair<int,int> bb){
    return aa.second < bb.second;
}
bool compare_first(pair<int,int> aa,pair<int,int> bb){
    return aa.first < bb.first;
}

bool sat[maxn];
bool vis[maxn];

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=make_pair(read(),i);
    for (int i=1;i<=n;i++) b[i]=read();
    sort(b+1,b+1+n);

    for (int i=n;i>=1;i--){
        int k=-1;
        for (int j=1;j<=n;j++) if (b[j]>a[i].first && !vis[j]) {k=j;break;}
        if (k==-1){
            for (int j=1;j<=n;j++) if (!vis[j]) {ans[i]=b[j],vis[j]=true;break;}
        } else ans[i]=b[k],vis[k]=true,sat[i]=true;
    }
    for (int i=1;i<=n;i++){
        int k=-1,now_max=ans[i];
        for (int j=i+1;j<=n;j++) if (ans[j]>now_max){
            int now=sat[i]+sat[j];
            int nxt=(ans[j]>a[i].first) + (ans[i]>a[j].first);
            if (nxt>=now) k=j,now_max=ans[j];
        }
        if (k!=-1){
            swap(ans[i],ans[k]);
            sat[i]=ans[i]>a[i].first;
            sat[k]=ans[k]>a[k].first;
        }
    }
    
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
