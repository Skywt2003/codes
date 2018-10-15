#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,m,fa[maxn],fib[maxn],max_num=0,min_num=0,all_white=0;
struct SideInfo{
    int x,y;
    bool w;
}a[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool CompareUp(SideInfo aa,SideInfo bb){
    return aa.w<bb.w;
}
inline bool CompareDown(SideInfo aa,SideInfo bb){
    return aa.w>bb.w;
}
inline int getfa(int x){
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}
inline void Kruscal(int k){
    for (int i=1;i<=n;i++) fa[i]=i;
    int white_num=0,black_num=0;
    for (int i=1;i<=m;i++){
        int fx=getfa(a[i].x),fy=getfa(a[i].y);
        if (a[i].w) black_num++; else white_num++;
        if (black_num+white_num==n-1) break;
    }
    if (black_num+white_num<n-1) return;
    if (k) max_num=white_num; else min_num=white_num;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        a[i].x=read(),a[i].y=read(),a[i].w=read();
        all_white+=1-a[i].w;
    }
    sort(a+1,a+1+m,CompareUp);
    Kruscal(1);
    sort(a+1,a+1+m,CompareDown);
    Kruscal(0);
    fib[1]=1;fib[2]=2;
    for (int i=1;i<=m;i++){
        if (i!=1&&i!=2) fib[i]=fib[i-1]+fib[i-2];
        if (fib[i]>all_white) break;
        if (fib[i]>=min_num&&fib[i]<=max_num) {printf("Yes\n");return 0;}
    }
    printf("No\n");
    return 0;
}