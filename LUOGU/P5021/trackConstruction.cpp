#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=50005,maxe=100005;

int n,m;
int tot=0,lnk[maxn],nxt[maxe],w[maxe],to[maxe];

void add_edge(int x,int y,int z){
    tot++; to[tot]=y; w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

#define mid (((R-L)>>1)+L)

int cnt=0;
int L=0,R=0,ans=-1;

int DFS(int x,int fa,int k){
    printf("Start to DFS: %lld\n",x);
    multiset<int> s; s.clear();
    multiset<int>::iterator it,found;
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
        int nxt=DFS(to[i],x,k)+w[i];
        if (nxt>=k) cnt++; else s.insert(nxt);
    }
    if (s.empty()) return 0;
    
    printf("now:");for (it=s.begin();it!=s.end();it++) printf("%lld ",(*it)); printf("\n");

    for (it=s.begin();(it!=s.end())&&(!s.empty());it++){
        found=s.lower_bound(k-(*it));
        if (found==s.end()) continue;
        if (found==it){
            found++;
            if (found==s.end()) continue;
        }
        s.erase(it); s.erase(found); cnt++;
    }
    printf("Ending DFS: %lld\n",x);
    if (s.empty()) return 0;
    return *(s.rbegin());
}

bool check(int k){
    printf("Start to check mid=%lld\n",mid);
    cnt=0;
    DFS(1,-1,k);
    return cnt>=m;
}

signed main(){
    n=read(); m=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read(),z=read();R+=z;
        add_edge(x,y,z);add_edge(y,x,z);
    }

    while (L<=R) if (check(mid)) ans=mid,L=mid+1; else R=mid-1;

    printf("%lld\n",ans);
    return 0;
}