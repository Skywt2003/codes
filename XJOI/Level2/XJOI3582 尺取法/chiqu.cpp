#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100005;
int n,s,a[maxn],ans=1<<30,INF=1<<30;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();s=read();
    for (int i=1;i<=n;i++) a[i]=read();
    int head=-1,tail=0,sum=0;
    while (head<=n&&tail<=n){
        sum-=a[head++];
        if (head>n) break;
        while (sum<s&&tail<=n) sum+=a[++tail];
        if (tail>n&&sum<s) break;
        while (sum-a[head]>=s) sum-=a[head++];
        if (tail-head+1<ans) ans=tail-head+1;
    }
    if (ans==INF) printf("0\n"); else printf("%d\n",ans);
    return 0;
}