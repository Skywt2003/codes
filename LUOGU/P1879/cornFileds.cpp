#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=15,maxs=4096+5;
const int tt=100000000;

int n,m,alls,a[maxn][maxn];
int blocked[maxn];
int f[maxn][maxs];

void add(int&x,int y){
    x=(x+y)%tt;
}

bool check(int x){
    for (int i=1;i<m;i++) if ((x&(1<<i))&&(x&(1<<(i-1)))) return false;
    return true;
}

signed main(){
    n=read();m=read(); alls=1<<m;
    for (int i=1;i<=n;i++){
        for (int j=0;j<m;j++){
            int x=read();
            if (!x) blocked[i]|=(1<<j);
        }
    }
    f[0][0]=1;
    for (int i=1;i<=n;i++)
    for (int j=0;j<alls;j++) if (check(j) && ((blocked[i]&j)==0))
    for (int k=0;k<alls;k++) if (check(k) && ((blocked[i-1]&k)==0) && ((j&k)==0)){
        add(f[i][j],f[i-1][k]);
    }
    int ans=0;
    for (int i=0;i<alls;i++) if (check(i) && (blocked[n]&i)==0) add(ans,f[n][i]);
    printf("%lld\n",ans);
    return 0;
}