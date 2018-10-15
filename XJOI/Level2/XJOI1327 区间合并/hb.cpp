#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=105;
int n,cnt=0;
struct WT{
    int x,f;
}a[maxn*2];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline bool cmp(WT aa,WT bb){
    return aa.x<bb.x;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read(),y=read();
        a[++cnt].x=x;a[cnt].f=1;
        a[++cnt].x=y;a[cnt].f=-1;
    }
    sort(a+1,a+1+cnt,cmp);
    int count=0;
    for (int i=1;i<=cnt;i++){
        int lstc=count;
        count+=a[i].f;
        if (lstc==0&&count) printf("%d ",a[i].x); else
        if (lstc&&count==0) printf("%d\n",a[i].x);
    }
    return 0;
}