#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=205,maxk=55,maxv=5005;

int k,v,n;
pair<int,int> a[maxn];

int f[maxv][maxk];
int now[maxk];

#define tmp1 f[j]
#define tmp2 f[j-a[i].first]

signed main(){
    k=read();v=read();n=read();
    for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=read();

    f[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=v;j>=a[i].first;j--){
            int ii=1,jj=1;now[0]=0;
            for (int t=1;t<=k;t++){
                if (ii>tmp1[0] && jj>tmp2[0]) break;
                if (ii<=tmp1[0] && (jj>tmp2[0] || tmp1[ii]>tmp2[jj]+a[i].second)) now[t]=tmp1[ii],ii++;
                else now[t]=tmp2[jj]+a[i].second,jj++;
                now[0]++;
            }
            for (int t=0;t<=k;t++) f[j][t]=now[t];
        }

    int ans=0;
    for (int i=1;i<=k;i++) ans+=f[v][i];
    printf("%d\n",ans);
    return 0;
}