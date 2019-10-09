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
const int INF=0x3f3f3f3f3f3f3f3f;

int n,k;
int a[maxn];
vector<int> vec[maxn];
int ans=0;

signed main(){
    n=read(); k=read();
    for (int i=1;i<=n;i++) a[i]=read(),vec[i%k].push_back(a[i]);
    for (int i=0;i<k;i++){
        int sum=0,min_num=INF;
        for (int j=0;j<vec[i].size();j++){
            sum+=vec[i][j];
            if ((j&1)==0) min_num=min(min_num,vec[i][j]);
        }
        ans+=sum-((vec[i].size()&1)?min_num:0);
    }
    printf("%lld\n",ans);
    return 0;
}