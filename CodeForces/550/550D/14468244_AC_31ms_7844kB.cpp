#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000005,maxe=2000005;
int n,tot,k;
struct Answer{
    int s,t;
}ans[maxn];
inline void add(int x,int y){
    tot++;
    ans[tot].s=x;ans[tot].t=y;
}
inline bool cmp(Answer aa,Answer bb){
    return (aa.s<bb.s||(aa.s==bb.s&&aa.t<bb.t));
}
int main(){
    scanf("%d",&k);
    if (k==1){
        printf("YES\n2 1\n1 2\n");
        return 0;
    }
    if (!(k&1)){printf("NO\n");return 0;}
    int delta=k+2;
    add(1,delta+1);
    for (int i=2;i<=k;i++) add(1,i);
    for (int i=2;i<=k;i++)
    for (int j=i+1;j<=k;j++) if ((i>>1)-(j>>1)) add(i,j);
    for (int i=2;i<=k;i++){
        add(k+1,i);
        add(k+2,i);
    }
    add(k+1,k+2);
    for (int i=delta+2;i<=delta+k;i++) add(delta+1,i);
    for (int i=delta+2;i<=delta+k;i++)
    for (int j=i+1;j<=delta+k;j++) if (((i-delta)>>1)-((j-delta)>>1)) add(i,j);
    for (int i=delta+2;i<=delta+k;i++){
        add(delta+k+1,i);
        add(delta+k+2,i);
    }
    add(delta+k+1,delta+k+2);
    printf("YES\n");
    printf("%d %d\n",2*k+4,tot);
    // sort(ans+1,ans+1+tot,cmp);
    for (int i=1;i<=tot;i++) printf("%d %d\n",ans[i].s,ans[i].t);
    return 0;
}
