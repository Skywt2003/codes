#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n;
long long tree[maxn],ans[maxn];
struct NodeInfo{
    int x,id;
}a[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool cmp(NodeInfo aa,NodeInfo bb){
    return (aa.x<bb.x||(aa.x==bb.x&&aa.id<bb.id));
}
inline int lowbit(int x){
    return x&(-x);
}
inline void add(int x){
    if (x==0) return;
    while (x<n){
        tree[x]++;
        x+=lowbit(x);
    }
}
inline long long query(int x){
    if (x<0) return 0;
    long long ret=0;
    while (x){
        ret+=tree[x];
        x-=lowbit(x);
    }
    return ret;
}
int main(){
    n=read();
    for (int i=0;i<n;i++) a[i].x=read(),a[i].id=i;
    sort(a,a+n,cmp);
    for (int i=0;i<n;i++){
        for (int j=1;j*a[i].id+1<n&&j<n;j++){
            ans[j]+=(long long)query(min(n-1,j*a[i].id+j))-query(j*a[i].id);
        }
        add(a[i].id);
    }
    for (int i=1;i<n;i++) printf("%lld ",ans[i]);printf("\n");
    return 0;
}