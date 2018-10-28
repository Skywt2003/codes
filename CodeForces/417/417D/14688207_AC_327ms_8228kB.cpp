#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=105,maxm=25,maxx=1048580;
int n,m,s,c;
long long INF,ans,f[maxx];
struct ClassmateData{
    int cost,monitor,solve_num,solve;
}a[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool cmp(ClassmateData aa,ClassmateData bb){
    return aa.monitor<bb.monitor;
}
int main(){
    n=read();m=read();c=read();
    s=1<<m;
    for (int i=1;i<=n;i++){
        a[i].cost=read(),a[i].monitor=read(),a[i].solve_num=read();
        a[i].solve=0;
        for (int j=0;j<a[i].solve_num;j++){
            int x=read();x--;
            a[i].solve+=1<<x;
        }
    }
    sort(a+1,a+1+n,cmp);
    memset(f,63,sizeof(f));
    INF=f[0];ans=INF;f[0]=0;
    for (int i=1;i<=n;i++){
        for (int j=s-1;j>=0;j--){
            if (j|a[i].solve<s) f[j|a[i].solve]=min(f[j|a[i].solve],f[j]+(long long)a[i].cost);
        }
        ans=min(ans,f[s-1]+(long long)a[i].monitor*(long long)c);
    }
    if (ans>=INF) printf("-1\n"); else printf("%lld\n",ans);
    return 0;
}
