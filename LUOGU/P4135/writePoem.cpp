#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005,maxb=305,maxc=355;
int n,c,m,b,nn=0;
int a[maxn];
int cnt[maxb][maxn],f[maxb][maxb];
int cur[maxn];
int que[maxc*2];
pair<int,int> block[maxb];

void build_block(){
    b=max((int)sqrt(n),n/300);
    for (int i=1,id=1;i<=n;i+=b,id++,nn++) block[id]=make_pair(i,min(i+b-1,n));

    for (int i=1;i<=nn;i++){
        for (int j=1;j<=c;j++) cnt[i][j]=cnt[i-1][j];
        for (int j=block[i].first;j<=block[i].second;j++) cnt[i][a[j]]++;
    }

    for (int i=1;i<=nn;i++){
        for (int j=i;j<=nn;j++){
            f[i][j]=f[i][j-1];
            for (int k=block[j].first;k<=block[j].second;k++) cur[a[k]]++;
            for (int k=block[j].first;k<=block[j].second;k++) if (cur[a[k]]){
                if ((cnt[j-1][a[k]]-cnt[i-1][a[k]])==0){
                    f[i][j]+=((cur[a[k]]&1)==0);
                } else {
                    int pre=cnt[j-1][a[k]]-cnt[i-1][a[k]];
                    if (cur[a[k]]&1) f[i][j]+=(pre&1)?1:-1;
                }
                cur[a[k]]=0;
            }
        }
    }
}

int query(int x,int y){
    int tail=0;
    int l=x,r=y,bl,br;
    for (int i=1;i<=nn;i++){
        if (block[i].first<=x && x<=block[i].second) bl=i;
        if (block[i].first<=y && y<=block[i].second) br=i;
    }
    while (l+1<=r && l<=block[bl].second) que[++tail]=a[l],l++;
    while (l<=r-1 && r>=block[br].first)  que[++tail]=a[r],r--;
    if (l==r) que[++tail]=a[l];
    bl++;br--;

    int ret=(bl<=br)?(f[bl][br]):0;
    for (int k=1;k<=tail;k++) cur[que[k]]++;
    for (int k=1;k<=tail;k++) if (cur[que[k]]){
        if ((bl>br) || (cnt[br][que[k]]-cnt[bl-1][que[k]]==0)){
            ret+=((cur[que[k]]&1)==0);
        } else {
            int pre=cnt[br][que[k]]-cnt[bl-1][que[k]];
            if (cur[que[k]]&1) ret+=(pre&1)?1:-1;
        }
        cur[que[k]]=0;
    }
    return ret;
}

signed main(){
    n=read();c=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    build_block();
    int ans=0;
    while (m--){
        int l=read(),r=read();
        l=(l+ans)%n+1,r=(r+ans)%n+1; if (l>r) swap(l,r);
        ans=query(l,r);
        printf("%d\n",ans);
    }
    return 0;
}