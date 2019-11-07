#include<bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
 
const int tt=998244353;
const int maxn=10,maxs=390625+10;
 
int n,m,b[maxn];
int f[maxn][maxs];
 
namespace subtask5{
    signed main(){
        printf("%lld\n",n);
        return 0;
    }
};
 
bool is_subset(int s1,int s2){
    while (s2){
        if (s1%5 > s2%5) return false;
        s1/=5; s2/=5;
    }
    return true;
}
 
signed main(){
    n=read(); m=read();
    for (int i=0;i<n;i++) b[i]=read();
     
    if (m==2) return subtask5::main();
     
    int s=0;
    for (int i=0;i<n;i++) s=s*5+b[i];
     
    f[0][s]=1;
    for (int i=1;i<m;i++)
        for (int j=0;j<=s;j++)
            for (int k=0;k<j;k++)
                if (is_subset(k,j)) f[i][k]=(f[i][k]+f[i-1][j])%tt;
    int ans=0;
    for (int i=0;i<=s;i++) ans=(ans+f[m-1][i])%tt;
    printf("%lld\n",ans);
    return 0;
}