#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=400005,maxc=22;
const int maxs=1048576+10;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,c=20,s=1<<20;
int a[maxn];
int cnt[maxc][maxc];
int f[maxs];
vector<int> vec[maxc];

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read()-1,vec[a[i]].push_back(i);

    for (int i=0;i<c;i++) if (vec[i].size())
        for (int j=0;j<c;j++) if (vec[j].size() && i!=j){
            int t=0;
            for (int k=0;k<vec[i].size();k++){
                while ((vec[j][t]<vec[i][k]) && (t+1<vec[j].size())) t++;
                cnt[i][j]+=t+(vec[j][t]<vec[i][k]);
            }
        }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for (int i=0;i<s;i++) if (f[i]!=INF){
        for (int j=0;j<c;j++) if ((i&(1<<j))==0){
            int nxt=i|(1<<j);
            int sum=0;
            for (int k=0;k<c;k++) if (i&(1<<k)) sum+=cnt[j][k];
            f[nxt]=min(f[nxt],f[i]+sum);
        }
    }
    printf("%lld\n",f[s-1]);
    return 0;
}