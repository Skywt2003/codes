#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const bool debug=false;

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1005;

int n;
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];

int max_son[maxn],siz[maxn];
int c=-1,max_num=0;
int sum[4];

vector<int> vec[4],allvec;
vector<int> g1,g2;

struct edge{
    int x,y,w;
};
edge ans[maxn];
int ans_cnt=0;

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void find_cg(int x,int fa){
    siz[x]=1;
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
        find_cg(to[i],x);
        siz[x]+=siz[to[i]];
        max_son[x]=max(max_son[x],siz[to[i]]);
    }
    if (max(max_son[x],n-siz[x]) < max_num) max_num=max(max_son[x],n-siz[x]),c=x;
}

void build_tree(int x,int fa){
    siz[x]=1;
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
        build_tree(to[i],x);
        siz[x]+=siz[to[i]];
    }
}

void make_subanswer(int x,int fa,int s,int t,int k){
    int nowt=s;
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
        ans[++ans_cnt]=(edge){x,to[i],k*nowt};
        make_subanswer(to[i],x,1,siz[to[i]]-1,k);
        nowt+=siz[to[i]];
    }
}

void make_answer(int c,vector<int> g,int s,int t,int k){
    if (debug) printf("Make answer k=%lld\n",k);
    int nowt=s;
    for (int i=0;i<g.size();i++){
        if (debug) printf("nowt = %lld\n",nowt);
        ans[++ans_cnt]=(edge){c,g[i],k*nowt};
        make_subanswer(g[i],c,1,siz[g[i]]-1,k);
        nowt+=siz[g[i]];
    }
}

signed main(){
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y);add_edge(y,x);
    }
    if (n==1) return 0; else
    if (n==2){
        printf("1 2 1\n");
        return 0;
    }

    max_num=INF;
    find_cg(1,-1);
    if (debug) printf("Center: %lld\n",c);
    memset(siz,0,sizeof(siz));
    build_tree(c,-1);

    for (int i=lnk[c];i;i=nxt[i]) allvec.push_back(to[i]);
    if (allvec.size() == 2){
        g1.push_back(allvec[0]);
        g2.push_back(allvec[1]);
    } else {
        sum[0]=siz[allvec[0]]; vec[0].push_back(allvec[0]);
        sum[1]=siz[allvec[1]]; vec[1].push_back(allvec[1]);
        sum[2]=siz[allvec[2]]; vec[2].push_back(allvec[2]);
        if (allvec.size() >= 4){
            for (int i=3;i<allvec.size();i++) sum[3]+=siz[allvec[i]],vec[3].push_back(allvec[i]);
            for (int i=0;i<4;i++)
                for (int j=i+1;j<4;j++)
                    if (sum[i]+sum[j]<=n/2){
                        sum[i]+=sum[j];
                        for (int k=0;k<vec[j].size();k++) vec[i].push_back(vec[j][k]);
                        sum[j]=0; vec[j].clear();
                    }
        }
        if (allvec.size() >= 3){
            int k=-1,now_max=0;
            for (int i=0;i<4;i++) if (sum[i]>now_max) now_max=sum[i],k=i;
            for (int i=0;i<4;i++) if (sum[i]!=-1 && i==k){
                for (int j=0;j<vec[i].size();j++) g1.push_back(vec[i][j]);
            } else {
                for (int j=0;j<vec[i].size();j++) g2.push_back(vec[i][j]);
            }
        }
    }

    if (debug){
        printf("Delivered into groups: \n");
        for (int i=0;i<g1.size();i++) printf("%lld ",g1[i]);printf("\n");
        for (int i=0;i<g2.size();i++) printf("%lld ",g2[i]);printf("\n");
        printf("End. ---\n");
    }

    // int sa=g1.size(),sb=g2.size();
    int sa=0,sb=0;
    for (int i=0;i<g1.size();i++) sa+=siz[g1[i]];
    for (int i=0;i<g2.size();i++) sb+=siz[g2[i]];
    make_answer(c,g1,1,sa,1);
    make_answer(c,g2,1,sb,sa+1);

    for (int i=1;i<n;i++) printf("%lld %lld %lld\n",ans[i].x,ans[i].y,ans[i].w);
    return 0;
}