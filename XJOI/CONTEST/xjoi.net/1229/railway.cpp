#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=480000;
const int INF=1<<30;
int c,s,r;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

#define ls (p<<1)
#define rs (p<<1|1)
#define mid (((tr-tl)>>1)+tl)

class segmentTree{
	private:
		int tree[maxn*4],tag[maxn*4];

		void push_down(int tl,int tr,int p){
			tree[ls]-=tag[p];tree[rs]-=tag[p];
			tag[ls]+=tag[p];tag[rs]+=tag[p];
			tag[p]=0;
		}

	public:
		segmentTree(){
			memset(tree,0,sizeof(tree));
			memset(tag,0,sizeof(tag));
		}

		void build_tree(int tl,int tr,int p){
			if (tl==tr){
				tree[p]=s;
				return;
			}
			build_tree(tl,mid  ,ls);
			build_tree(mid+1,tr,rs);
			tree[p]=min(tree[ls],tree[rs]);
		}

		void update(int sl,int sr,int tl,int tr,int p,int delta){
			if (sl<=tl && tr<=sr){
				tree[p]-=delta;
				tag[p]+=delta;
				return;
			}
			push_down(tl,tr,p);
			if (sl  <=mid) update(sl,sr,tl,mid  ,ls,delta);
			if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
			tree[p]=min(tree[ls],tree[rs]);
		}

		int query(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return tree[p];
			push_down(tl,tr,p);
			int ret=INF;
			if (sl  <=mid) ret=min(ret,query(sl,sr,tl,mid  ,ls));
			if (mid+1<=sr) ret=min(ret,query(sl,sr,mid+1,tr,rs));
			return ret;
		}
};

segmentTree t;

signed main(){
    c=read(),s=read(),r=read();
    t.build_tree(1,c,1);
    for(int i=1;i<=r;i++){
        int x=read(),y=read(),z=read();
        y--;
        int now=t.query(x,y,1,c,1);
        if (z<=now){
            printf("T\n");
            t.update(x,y,1,c,1,z);
        } else printf("N\n");
    }
    return 0;
}