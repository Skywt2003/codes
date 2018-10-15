#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,p[maxn];
long long f[maxn][2],INF;
string s[maxn]; //Van:  reverse(s.begin(),s.end());
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) p[i]=read();
    for (int i=1;i<=n;i++) cin>>s[i];
    memset(f,63,sizeof(f));
    INF=f[0][0];
    f[1][1]=(long long)p[1];f[1][0]=0;
    for (int i=2;i<=n;i++){
        string tmp1=s[i-1],tmp2=s[i];
        reverse(tmp1.begin(),tmp1.end());
        reverse(tmp2.begin(),tmp2.end());
        // cout<<tmp1<<endl<<tmp2;
        if (s[i]>=s[i-1]) f[i][0]=min(f[i][0],f[i-1][0]);
        if (s[i]>=tmp1) f[i][0]=min(f[i][0],f[i-1][1]);
        if (tmp2>=s[i-1]) f[i][1]=min(f[i][1],f[i-1][0]+(long long)p[i]);
        if (tmp2>=tmp1) f[i][1]=min(f[i][1],f[i-1][1]+(long long)p[i]);
    }
    long long ans=min(f[n][0],f[n][1]);
    if (ans==INF) printf("-1\n"); else printf("%lld\n",ans);
    return 0;
}
