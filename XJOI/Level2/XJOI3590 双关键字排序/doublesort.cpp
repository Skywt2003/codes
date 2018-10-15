#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n;
struct NumData{
    int x,y;
}a[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool cmp(NumData aa,NumData bb){
    return (aa.x<bb.x)||((aa.x==bb.x)&&(aa.y<bb.y));
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++) printf("%d %d\n",a[i].x,a[i].y);
    return 0;
}