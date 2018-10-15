#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,h[maxn],top=0,lft[maxn],rght[maxn];
long long ans=0;
struct StuckData{
    int x,v;
}stk[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) h[i]=read();
    stk[0].x=1;
    for (int i=1;i<=n;i++) lft[i]=i;
    for (int i=1;i<=n;i++){
        if (top==0||h[i]>stk[top].v){
            top++;
            stk[top].v=h[i];stk[top].x=i;
        } else {
            while (stk[top-1].v>=h[i]&&top-1>=0) top--;
            lft[i]=lft[stk[top].x];
            top++;stk[top].x=i;stk[top].v=h[i];
        }
    }
    for (int i=1;i<=n/2;i++) swap(h[i],h[n-i+1]);top=0;
    for (int i=1;i<=n;i++) rght[i]=i;
    for (int i=1;i<=n;i++){
        if (top==0||h[i]>stk[top].v){
            top++;
            stk[top].v=h[i];stk[top].x=i;
        } else {
            while (stk[top-1].v>=h[i]&&top-1>=0) top--;
            rght[i]=rght[stk[top].x];
            top++;stk[top].x=i;stk[top].v=h[i];
        }
    }
    for (int i=1;i<=n/2;i++) swap(rght[i],rght[n-i+1]);
    for (int i=1;i<=n;i++) rght[i]=n-rght[i]+1;
    for (int i=1;i<=n/2;i++) swap(h[i],h[n-i+1]);

    // for (int i=1;i<=n;i++) printf("LFT=%d,  RGHT=%d\n",lft[i],rght[i]);
    for (int i=1;i<=n;i++){
        if ((long long)(rght[i]-lft[i]+1)*(long long)h[i]>ans) ans=(long long)(rght[i]-lft[i]+1)*(long long)h[i];
    }
    printf("%lld\n",ans);
    return 0;
}