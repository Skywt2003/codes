#include<bits/stdc++.h>
using namespace std;

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

inline int Abs(int x){
    return (x<0)?-x:x;
}

const int maxn=1500005;

#define ls(x) tree[x].child[0]
#define rs(x) tree[x].child[1]

class treap{
    private:
        struct Node{
        	int value,key,size;
        	int child[2];
        	void clear(){value=key=size=child[0]=child[1]=0;}
        }tree[maxn];
        
        int tot,root;
        
        void update(int x){
        	tree[x].size=tree[ls(x)].size+tree[rs(x)].size+1;
        }
           
        int merge(int x,int y){
        	if (!x||!y) return x|y;
        	if (tree[x].key < tree[y].key){
        		rs(x)=merge(rs(x),y);
        		update(x);return x;
        	} else {
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
        	update(now);
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
};

const int INF=1<<30;

int n,q;
int a[maxn],head[maxn],tail[maxn];
treap t1,t2;
int minn=INF;

inline char read_char(){
	char ch=getchar(); while (ch!='I' && ch!='M' && ch!='G' && ch!='S') ch=getchar();
	return ch;
}

signed main(){
	t1.init(); t2.init();
	n=read();q=read();
	for (int i=1;i<=n;i++){
		a[i]=head[i]=tail[i]=read();
		t1.insertNode(a[i]);
		if (i!=1) t2.insertNode(Abs(a[i]-a[i-1]));
	}
	sort(a+1,a+1+n);
	for (int i=2;i<=n;i++) minn=min(minn,Abs(a[i]-a[i-1]));
	
	for (int i=1;i<=q;i++){
		char c1=read_char();
		if (c1=='I'){
            // printf("opt1\n");
			int x=read(),value=read();
			if (x!=n){
                t2.deleteNode(Abs(head[x+1]-tail[x]));
                t2.insertNode(Abs(head[x+1]-value));
            }
            t2.insertNode(Abs(tail[x]-value));
            tail[x]=value;
            if (t1.findNode(value)) minn=0; else {
                int x1=t1.getPre(value),x2=t1.getNext(value);
                minn=min(minn,min(Abs(value-x1),Abs(value-x2)));
            }
            t1.insertNode(value);
		} else {
			char c2=read_char();c2=read_char();
			if (c2=='G'){
                // printf("opt2\n");
				printf("%d\n",t2.getMin());
			} else {
                // printf("opt3\n");
                printf("%d\n",minn);
                c2=read_char();
            }
		}
	}
    return 0;
}
