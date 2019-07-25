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

class treap{
    private:
        struct Node{
        	int value,key,size,tag;
        	int child[2];
        	void clear(){value=key=size=tag=child[0]=child[1]=0;}
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
            pushdown(now);
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
        
        void deleteNode(int value){
        	int lTree,mid1,mid2,rTree;
        	splitValue(root,value-1,lTree,mid1),splitRank(mid1,1,mid2,rTree);
        	tree[mid2].clear();
        	root=merge(lTree,rTree);
        }
        
        int getRank(int value){
        	int lTree,rTree,ret;
        	splitValue(root,value-1,lTree,rTree);
        	ret=tree[lTree].size+1;
        	root=merge(lTree,rTree);
        	return ret;
		}

        int getValue(int rank){
        	int lTree,m1,mTree,ret,rTree;
        	splitRank(root,rank-1,lTree,m1);
        	splitRank(m1,1,mTree,rTree);
        	ret=tree[mTree].value;
        	root=merge(merge(lTree,mTree),rTree);
        	return ret;
        }

        int getValue(int &root,int rank){
        	int lTree,m1,mTree,ret,rTree;
        	splitRank(root,rank-1,lTree,m1);
        	splitRank(m1,1,mTree,rTree);
        	ret=tree[mTree].value;
        	root=merge(merge(lTree,mTree),rTree);
        	return ret;
        }
        
        int getPre(int value){
        	int lTree,rTree,ret;
        	splitValue(root,value-1,lTree,rTree);
        	ret=getValue(lTree,tree[lTree].size);
        	root=merge(lTree,rTree);
        	return ret;
        }
        
        int getNext(int value){
        	int lTree,rTree,ret;
        	splitValue(root,value,lTree,rTree);
        	ret=getValue(rTree,1);
        	root=merge(lTree,rTree);
        	return ret;
        }

        bool findNode(int value){
            int now=root;
            while (tree[now].size!=0 && tree[now].value!=value){
                now=tree[now].child[value > tree[now].value];
            }
            return tree[now].value==value;
        }

        int getMin(){
            int now=root;
            while (tree[ls(now)].size!=0) now=ls(now);
            return tree[now].value;
        }

        void rotateInterval(int l,int r){
            int lTree,mTree,tmp,rTree;
            splitRank(root,r,tmp,rTree);
            splitRank(tmp,l-1,lTree,mTree);
            tree[mTree].tag^=1;
            root=merge(merge(lTree,mTree),rTree);
        }
};

signed main(){
    
}