// 190722

#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005,maxe=200005;
int n,m,root,tt;
int v[maxn];

void plusMod(int &x,int y){x=(x+y)%tt;}
void minsMod(int &x,int y){x=(x-y+tt)%tt;}

class segmentTree{
    
    #define ls ((p<<1))
    #define rs ((p<<1)+1)
    #define mid (((tr-tl)>>1)+tl)

    private:
        int tree[maxn*4],tag[maxn*4];

        void push_down(int tl,int tr,int p){
            plusMod(tree[ls],tag[p]*(mid-tl+1)%tt);
            plusMod(tree[rs],tag[p]*(tr-mid)%tt);
            plusMod(tag[ls],tag[p]); plusMod(tag[rs],tag[p]);
            tag[p]=0;
        }

    public:
        void init(){
            memset(tree,0,sizeof(tree));
            memset(tag,0,sizeof(tag));
        }

        void update(int sl,int sr,int tl,int tr,int p,int delta){
            if (sl<=tl && tr<=sr){
                plusMod(tree[p],delta*(tr-tl+1)%tt);
                plusMod(tag[p],delta);
                return;
            }
            push_down(tl,tr,p);
            if (sl<=mid  ) update(sl,sr,tl,mid,ls,delta);
            if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
            tree[p]=(tree[ls]+tree[rs])%tt;
        }

        void update(int x,int tl,int tr,int p,int delta){
            if (tl==tr && tl==x){
                plusMod(tree[p],delta);
                return;
            }
            push_down(tl,tr,p);
            if (x<=mid  ) update(x,tl,mid,ls,delta);
            if (mid+1<=x) update(x,mid+1,tr,rs,delta);
            tree[p]=(tree[ls]+tree[rs])%tt;
        }

        int query(int sl,int sr,int tl,int tr,int p){
            if (sl<=tl && tr<=sr) return tree[p];
            push_down(tl,tr,p);
            int ret=0;
            if (sl<=mid  ) plusMod(ret,query(sl,sr,tl,mid,ls));
            if (mid+1<=sr) plusMod(ret,query(sl,sr,mid+1,tr,rs));
            return ret;
        }

        int query(int x,int tl,int tr,int p){
            if (tl==tr && tl==x) return tree[p];
            push_down(tl,tr,p);
            int ret=0;
            if (x<=mid  ) plusMod(ret,query(x,tl,mid,ls));
            if (mid+1<=x) plusMod(ret,query(x,mid+1,tr,rs));
            return ret;
        }
};

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int size[maxn],son[maxn],fa[maxn],deep[maxn];
int top[maxn],id[maxn],cnt=0;
segmentTree t;

void addEdge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

void buildTree(int x){
    size[x]=1,son[x]=-1;
    int maxson=0;
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
        deep[to[i]]=deep[x]+1;fa[to[i]]=x;
        buildTree(to[i]);
        size[x]+=size[to[i]];
        if (size[to[i]]>maxson) maxson=size[to[i]],son[x]=to[i];
    }
}

void buildChain(int x){
    id[x]=++cnt;
    if (son[fa[x]]==x) top[x]=top[fa[x]]; else top[x]=x;
    if (son[x]!=-1) buildChain(son[x]);
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x] && to[i]!=son[x]) buildChain(to[i]);
}

void updateChain(int x,int y,int delta){
    while (top[x]!=top[y]){
        if (deep[top[x]]<deep[top[y]]) swap(x,y);
        t.update(id[top[x]],id[x],1,n,1,delta);
        x=fa[top[x]];
    }
    if (id[x]<id[y]) swap(x,y);
    t.update(id[y],id[x],1,n,1,delta);
}

int querySumChain(int x,int y){
    int ret=0;
    while (top[x]!=top[y]){
        if (deep[top[x]]<deep[top[y]]) swap(x,y);
        plusMod(ret,t.query(id[top[x]],id[x],1,n,1));
        x=fa[top[x]];
    }
    if (id[x]<id[y]) swap(x,y);
    plusMod(ret,t.query(id[y],id[x],1,n,1));
    return ret;
}

void updateSubtree(int x,int delta){
    t.update(id[x],id[x]+size[x]-1,1,n,1,delta);
}

int querySubtree(int x){
    return t.query(id[x],id[x]+size[x]-1,1,n,1);
}

signed main(){
    n=read();m=read();root=read();tt=read();
    for (int i=1;i<=n;i++) v[i]=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        addEdge(x,y);addEdge(y,x);
    }

    deep[root]=1;
    buildTree(root);
    buildChain(root);

    for (int i=1;i<=n;i++) t.update(id[i],1,n,1,v[i]%tt);

    while (m--){
        int opt=read();
        if (opt==1){
            int x=read(),y=read(),z=read()%tt;
            updateChain(x,y,z);
        } else if (opt==2){
            int x=read(),y=read();
            printf("%d\n",querySumChain(x,y));
        } else if (opt==3){
            int x=read(),z=read()%tt;
            updateSubtree(x,z);
        } else if (opt==4){
            int x=read();
            printf("%d\n",querySubtree(x));
        }
    }

    return 0;
}