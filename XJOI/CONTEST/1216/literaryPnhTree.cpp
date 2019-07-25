// A bian4tai4 No Rotate Treap (I call it an "Extreap")

#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

inline int getRand(){
    static int seed=703;
    return seed=(int)(seed*48271%(~0u>>1));
}

const int maxn=500005;

#define ls(x) tree[x].child[0]
#define rs(x) tree[x].child[1]

class extreap{
    private:
        struct Node{
        	int value,key,size,tag;
        	int child[2];
        	void clear(){value=key=size=child[0]=child[1]=0;tag=0;}
        }tree[maxn];
	    
        int tot,root;
        
        void pushdown(int x){
            if (tree[x].tag==0) return;
            swap(ls(x),rs(x));
            tree[ls(x)].tag^=1,tree[rs(x)].tag^=1;
            tree[x].tag=0;
        }

        void update(int x){
        	tree[x].size=tree[ls(x)].size+tree[rs(x)].size+1;
        }
        
        int merge(int x,int y){
        	if (!x||!y) return x|y;
        	if (tree[x].key < tree[y].key){
                pushdown(x);
        		rs(x)=merge(rs(x),y);
        		update(x);return x;
        	} else {
                pushdown(y);
        		ls(y)=merge(x,ls(y));
        		update(y);return y;
        	}
        }
        
        void splitValue(int now,int k,int &x,int &y){
        	if (!now) return (void)(x=y=0);
        	if (tree[now].value <= k) x=now,splitValue(rs(now),k,rs(now),y);
        	else y=now,splitValue(ls(now),k,x,ls(now));
        	update(now);
        }
        
        void splitRank(int now,int k,int &x,int &y){
        	if (!now) return (void)(x=y=0);
            pushdown(now);
        	if (tree[ls(now)].size < k) x=now,splitRank(rs(now),k-tree[ls(now)].size-1,rs(now),y);
        	else y=now,splitRank(ls(now),k,x,ls(now));
        	update(now);
        }

        void printDFS(int now){
            pushdown(now);
            if (ls(now)) printDFS(ls(now));
            printf("%lld ",tree[now].value);
            if (rs(now)) printDFS(rs(now));
        }

    public:
        void init(){
        	tot=root=0;
        }
        
        void insertNode(int value){
        	int x=++tot,lTree,rTree;
        	tree[x].value=value,tree[x].key=getRand(),tree[x].size=1;
        	splitValue(root,value,lTree,rTree);
        	root=merge(merge(lTree,x),rTree);
        }

        void rotateInterval(int l,int r){
            int lTree,mTree,tmp,rTree;
            splitRank(root,r,tmp,rTree);
            splitRank(tmp,l-1,lTree,mTree);
            tree[mTree].tag^=1;
            root=merge(merge(lTree,mTree),rTree);
        }

        void printAll(){
            printDFS(root);
            printf("\n");
        }
};

extreap t;

int n,m;

signed main(){
    t.init();
    n=read(),m=read();
    for (int i=1;i<=n;i++) t.insertNode(i);
    // t.printAll();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        t.rotateInterval(x,y);
    }
    t.printAll();
    return 0;
}