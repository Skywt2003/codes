#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=200005;
int n,m,tree[2][maxn*4],tag[2][maxn*4],a[2][maxn],x[maxn],y[maxn],back[2][maxn];
map <int,int> mapto[2];
bool ques[maxn],vis[maxn]; // ques[i]=0: Left; ques[i]=1: Right.

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline char read_ch(){
    char ch=getchar();while (ch!='L'&&ch!='U') ch=getchar();
    return ch;
}

// Segment Tree (Get Max)
inline void push_down(int t,int tx,int ty,int p){ // t=0:Left Part; t=1:Right Part.
    if (tx==ty) return;
    int mid=((ty-tx)>>1)+tx;
    tree[t][p<<1]=max(tree[t][p<<1],tag[t][p]); // Relax tag[]
    tag[t][p<<1]=max(tag[t][p<<1],tag[t][p]);
    tree[t][(p<<1)+1]=max(tree[t][(p<<1)+1],tag[t][p]);
    tag[t][(p<<1)+1]=max(tag[t][(p<<1)+1],tag[t][p]);
    tag[t][p]=0;
    return;
}
inline void update(int t,int sx,int sy,int tx,int ty,int p,int nxt){
    if (sx<=tx&&ty<=sy){
        tree[t][p]=max(tree[t][p],nxt);
        tag[t][p]=max(tag[t][p],nxt);
        return;
    }
    push_down(t,tx,ty,p);
    int mid=((ty-tx)>>1)+tx; // Divide
    if (sx<=mid) update(t,sx,sy,tx,mid,p<<1,nxt),tree[t][p]=max(tree[t][p],tree[t][p<<1]);
    if (mid+1<=sy) update(t,sx,sy,mid+1,ty,(p<<1)+1,nxt),tree[t][p]=max(tree[t][p],tree[t][(p<<1)+1]);
}
inline int query(int t,int sx,int sy,int tx,int ty,int p){
    if (sx<=tx&&ty<=sy) return tree[t][p];
    push_down(t,tx,ty,p);
    int mid=((ty-tx)>>1)+tx,ret=0;
    if (sx<=mid) ret=max(ret,query(t,sx,sy,tx,mid,p<<1));
    if (mid+1<=sy) ret=max(ret,query(t,sx,sy,mid+1,ty,(p<<1)+1));
    return ret;
}

int main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        y[i]=a[1][i]=read();x[i]=a[0][i]=read();
        ques[i]=read_ch()=='U';
    }
    sort(a[0]+1,a[0]+1+m);
    sort(a[1]+1,a[1]+1+m); // Descret to make coordinate compression
    int cnt0=0,cnt1=0;
    for (int i=1;i<=m;i++){
        if (mapto[0][a[0][i]]==0) back[0][++cnt0]=a[0][i],mapto[0][a[0][i]]=cnt0;
        if (mapto[1][a[1][i]]==0) back[1][++cnt1]=a[1][i],mapto[1][a[1][i]]=cnt1;
    }
    // printf("Break Point 1 =======\n");
    for (int i=1;i<=m;i++){
        int xx=mapto[0][x[i]],yy=mapto[1][y[i]];
        // printf("Break Point 2 =======\n");
        if (ques[i]==0){ // Do Left
            if (vis[xx]) {printf("0\n");continue;} else vis[xx]=1;
            int lftmx=query(0,xx,xx,1,m,1);
            printf("%d\n",back[1][yy]-back[1][lftmx]); // Print the real length.
            update(1,lftmx+1,yy,1,m,1,xx);
        } else {
            if (vis[xx]) {printf("0\n");continue;} else vis[xx]=1;
            int upmx=query(1,yy,yy,1,m,1);
            printf("%d\n",back[0][xx]-back[0][upmx]);
            update(0,upmx+1,xx,1,m,1,yy);
        }
    }
    return 0;
}