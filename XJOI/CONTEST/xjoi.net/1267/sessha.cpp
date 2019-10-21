#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5;
const int INF=0x3f3f3f3f3f3f3f3f;

class segmentTree{
    #define ls (p<<1)
    #define rs (p<<1|1)
    #define mid (((tr-tl)>>1)+tl)
 
    private:
        int maxv[maxn*4],minv[maxn*4],sub[maxn*4];
        int tag[maxn*4];
 
        void push_down(int tl,int tr,int p){
            maxv[ls]+=tag[p]; minv[ls]+=tag[p];
            maxv[rs]+=tag[p]; minv[rs]+=tag[p];
            tag[ls]+=tag[p];tag[rs]+=tag[p];
            tag[p]=0;
        }
 
    public:
        segmentTree(){
            memset(maxv,0,sizeof(maxv));
            memset(minv,0,sizeof(minv));
			memset(sub,0,sizeof(sub));
            memset(tag,0,sizeof(tag));
        }
 
        void update(int sl,int sr,int tl,int tr,int p,int delta){
            if (sl<=tl && tr<=sr){
                maxv[p]+=delta;
                minv[p]+=delta;
                tag[p]+=delta;
                return;
            }
            push_down(tl,tr,p);
            if (sl  <=mid) update(sl,sr,tl,mid  ,ls,delta);
            if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
            maxv[p]=max(maxv[ls],maxv[rs]);
            minv[p]=min(minv[ls],minv[rs]);
			sub[p]=max(max(sub[ls],sub[rs]),maxv[rs]-minv[ls]);
        }
 
        int query_max(int sl,int sr,int tl,int tr,int p){
            if (sl<=0 || sr<=0) return 0;
            if (sl<=tl && tr<=sr) return maxv[p];
            push_down(tl,tr,p);
            int ret=-INF;
            if (sl  <=mid) ret=max(ret,query_max(sl,sr,tl,mid  ,ls));
            if (mid+1<=sr) ret=max(ret,query_max(sl,sr,mid+1,tr,rs));
            return ret;
        }
 
        int query_min(int sl,int sr,int tl,int tr,int p){
            if (sl<=0 || sr<=0) return 0;
            if (sl<=tl && tr<=sr) return minv[p];
            push_down(tl,tr,p);
            int ret=INF;
            if (sl  <=mid) ret=min(ret,query_min(sl,sr,tl,mid  ,ls));
            if (mid+1<=sr) ret=min(ret,query_min(sl,sr,mid+1,tr,rs));
            return ret;
        }

		int query_sub(int sl,int sr,int tl,int tr,int p){
			if (sl<=0 || sr<=0) return 0;
			if (sl<=tl && tr<=sr) return sub[p];
			push_down(tl,tr,p);
			int ret=0;
			if (sl  <=mid) ret=max(ret,query_sub(sl,sr,tl,mid,ls));
			if (mid+1<=sr) ret=max(ret,query_sub(sl,sr,mid+1,tr,rs));
			if (sl<=mid && mid+1<=sr)
				ret=max(ret,query_max(sl,sr,mid+1,tr,rs)-query_min(sl,sr,tl,mid,ls));
			return ret;
		}
 
    #undef ls
    #undef rs
    #undef mid
};

segmentTree t;


int n,a[maxn];
int q;

signed main(){
	n=read();
	char ch=getchar(); while (ch!='('&&ch!=')') ch=getchar();
	for (int i=1;i<=n;i++){
		a[i]=(ch=='(')?1:-1;
		t.update(i,n,1,n,1,a[i]);
		if (i==n) continue;
		ch=getchar(); while (ch!='('&&ch!=')') ch=getchar();
	}

	q=read();
	while (q--){
        int opt=read();
        if (opt==1){
            int x=read();
            if (a[x]==1) a[x]=-1,t.update(x,n,1,n,1,-2);
            else a[x]=1,t.update(x,n,1,n,1,2);
        } else if (opt==2){
            int x=read(),y=read();
            int ans=-(t.query_min(x,y,1,n,1)-t.query_min(x-1,x-1,1,n,1));
            printf("%lld\n",max(ans,0ll));
		} else if (opt==3){
			int x=read(),y=read(),ans=0;
			int std_line=t.query_max(x-1,x-1,1,n,1),std_r=t.query_max(y,y,1,n,1);

			int lower=max(0ll,std_line-t.query_min(x,y,1,n,1));
			int delta=t.query_sub(x,y,1,n,1);
			int fix=(lower==0)?t.query_min(x,y,1,n,1)-std_line:0;
			#ifdef DEBUG
				printf("lower=%lld delta=%lld std_line=%lld std_r=%lld\n",lower,delta,std_line,std_r);
			#endif
            ans=lower + max(0ll, max(std_line+delta+fix,t.query_max(x,y,1,n,1))-(std_r+lower));

			printf("%lld\n",ans);
		}
	}
	return 0;
}

/*

7
(())()(
4
2 2 6
3 2 6
1 3
3 2 6

1\n2\n1

5
)())(
5
3 2 3
1 3
2 4 5
2 4 5
2 2 4

1\n1\n1\n0


5
())))
1
3 1 2

1\n

5
)))()
1
3 3 5


5
(()))
1
3 1 5


 */