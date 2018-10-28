#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n,m,cnt=0;
long long ln[maxn],rn[maxn];
struct IslandData{
    long long L,R;
    int id;
    bool operator <(const IslandData b)const{
        return R>b.R;
    }
}isd[maxn];
struct BridgeData{
    long long x;
    int id;
    bool operator <(const BridgeData b)const{
        return x<b.x;
    }
}a[maxn];
struct Answer{
    int id,x;
}ans[maxn];
priority_queue <IslandData> heap;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline long long llread(){
    long long ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=(long long)-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=(long long)ret*(long long)10+(long long)(ch-'0'),ch=getchar();
    return (long long)ret*f;
}
inline bool cmp(IslandData aa,IslandData bb){
    return aa.L<bb.L;
}
inline bool cmp_id(Answer aa,Answer bb){
    return aa.id<bb.id;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) ln[i]=llread(),rn[i]=llread();
    for (int i=1;i<n;i++){
        IslandData now;
        now.L=ln[i+1]-rn[i];
        now.R=rn[i+1]-ln[i];
        now.id=i;
        isd[i]=now;
    }
    for (int i=1;i<=m;i++) a[i].x=llread(),a[i].id=i;
    sort(a+1,a+1+m);
    sort(isd+1,isd+n,cmp);
    int j=1;
    for (int i=1;i<=m;i++){
        while (j<n&&isd[j].L<=a[i].x&&a[i].x<=isd[j].R) heap.push(isd[j++]);
        if (heap.size()==0) continue;
        IslandData now=heap.top();heap.pop();
        if (now.R<a[i].x){
            printf("No\n");
            return 0;
        }
        ans[++cnt].id=now.id;ans[cnt].x=a[i].id;
    }
    if (cnt<n-1){printf("No\n");return 0;}
    printf("Yes\n");
    sort(ans+1,ans+1+cnt,cmp_id);
    for (int i=1;i<=cnt;i++) printf("%d ",ans[i].x);
    printf("\n");
    return 0;
}