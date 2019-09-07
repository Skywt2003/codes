#include<bits/stdc++.h>
using namespace std;

//#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline char read_ch(){
    char ch=getchar();
    while (ch!='A' && ch!='M') ch=getchar();
    return ch;
}

const int maxn=1000005;
const int maxsize=1005;

int n,q,tot,size;

struct block{
    int left,right,delta;
    pair<int,int> a[maxsize];
}b[maxsize];

bool compare_first(pair<int,int> aa,pair<int,int> bb){
    return aa.first < bb.first;
}
bool compare_second(pair<int,int> aa,pair<int,int> bb){
    return aa.second < bb.second;
}

int a[maxn];
int blt[maxn];

#define bx b[blt[x]]
#define by b[blt[y]]
#define bxs (bx.right-bx.left+1)
#define bys (by.right-by.left+1)

void update(int x,int y,int delta){
    if (blt[x]==blt[y]){
        sort(bx.a+1,bx.a+1+size,compare_second);
        for (int i=x-bx.left+1;i<=y-bx.left+1;i++) bx.a[i].first+=delta;
        sort(bx.a+1,bx.a+1+size,compare_first);
        return;
    }

    sort(bx.a+1,bx.a+1+bxs,compare_second);
    for (int i=x-bx.left+1;i<=bx.right-bx.left+1;i++) bx.a[i].first+=delta;
	sort(bx.a+1,bx.a+1+bxs,compare_first);

    sort(by.a+1,by.a+1+bys,compare_second);
    for (int i=1;i<=y-by.left+1;i++) by.a[i].first+=delta;
    sort(by.a+1,by.a+1+bys,compare_first);

    for (int i=blt[x]+1;i<=blt[y]-1;i++) b[i].delta+=delta;
}

#define mid (((R-L)>>1)+L)

int find_sublock(int id,int k){
    int size_now=b[id].right-b[id].left+1;
    int ret=size_now;
    int L=1,R=size_now;
    while (L<=R)
        if (b[id].a[mid].first+b[id].delta >= k) ret=mid,R=mid-1; else L=mid+1;
    return size_now-ret+1;
}

int find(int x,int y,int k){
    int ret=0;

    if (blt[x]==blt[y]){
        sort(bx.a+1,bx.a+1+size,compare_second);
        for (int i=x-bx.left+1;i<=y-bx.left+1;i++) ret+=bx.a[i].first+bx.delta>=k;
        sort(bx.a+1,bx.a+1+size,compare_first);
        return ret;
    }
    sort(bx.a+1,bx.a+1+bxs,compare_second);
    for (int i=x-bx.left+1;i<=bx.right-bx.left+1;i++) ret+=bx.a[i].first+bx.delta>=k;
    sort(bx.a+1,bx.a+1+bxs,compare_first);

    sort(by.a+1,by.a+1+bys,compare_second);
    for (int i=1;i<=y-by.left+1;i++) ret+=by.a[i].first+by.delta>=k;
    sort(by.a+1,by.a+1+bys,compare_first);

    for (int i=blt[x]+1;i<=blt[y]-1;i++) ret+=find_sublock(i,k);

    return ret;
}

signed main(){
//	freopen("testdata.in","r",stdin);
//	freopen("my.out","w",stdout);
	
    n=read();q=read();
    size=sqrt(n);
    for (int i=1;i<=n;i++) a[i]=read();

    // build blocks
    for (int i=1;i<=n;i+=size+1){
        b[++tot].left=i; b[tot].right=min(i+size,n);
        for (int j=b[tot].left;j<=b[tot].right;j++){
            b[tot].a[j-b[tot].left+1].first=a[j];
            b[tot].a[j-b[tot].left+1].second=j-b[tot].left+1;
            blt[j]=tot;
        }
        sort(b[tot].a+1,b[tot].a+1+b[tot].right-b[tot].left+1,compare_first);
    }

    while (q--){
        char ops=read_ch();
        int x=read(),y=read(),z=read();
        if (ops=='M') update(x,y,z); else printf("%d\n",find(x,y,z));
    }

    return 0;
}