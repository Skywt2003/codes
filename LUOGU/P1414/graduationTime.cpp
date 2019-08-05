#include<bits/stdc++.h>
using namespace std;

const int maxn=10005,maxx=1e6+5;
const int XX=1e6;
int n,a[maxn];
int cnt[maxx],max_num[maxn];

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=(int)sqrt(a[i]);j++) if (a[i]%j==0){
            cnt[j]++;
            if (j!=a[i]/j) cnt[a[i]/j]++;
        }
    }
    for (int i=1;i<=XX;i++) if (cnt[i]) max_num[cnt[i]]=i;
    for (int i=n;i>=1;i--) max_num[i]=max(max_num[i],max_num[i+1]);

    for (int i=1;i<=n;i++){
        printf("%d\n",max_num[i]?max_num[i]:1);
    }
    return 0;
}