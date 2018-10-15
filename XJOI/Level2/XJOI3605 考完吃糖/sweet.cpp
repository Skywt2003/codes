#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,a[maxn],lnk[maxn][5],f[maxn],s[maxn],que[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void Topology(){
    int head=0,tail=0;
    for (int i=1;i<=n;i++) if (f[i]==0) que[++tail]=i,s[i]=1;
    while (head!=tail){
        head++;
        for (int i=1;i<=lnk[que[head]][0];i++){
            int nxt=lnk[que[head]][i];
            f[nxt]--;
            if (s[que[head]]+1 > s[nxt]) s[nxt]=s[que[head]]+1;
            if (f[nxt]==0) que[++tail]=nxt;
        }
    }
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++){
        if (i-1>=1){
            if (a[i-1]>a[i]) lnk[i][++lnk[i][0]]=i-1,f[i-1]++;
        }
        if (i+1<=n){
            if (a[i+1]>a[i]) lnk[i][++lnk[i][0]]=i+1,f[i+1]++;
        }
    }
    Topology();
    int sum=0;
    for (int i=1;i<=n;i++) sum+=s[i];
    printf("%d\n",sum);
    return 0;
}