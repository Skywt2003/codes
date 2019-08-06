#include<bits/stdc++.h>

#define ls (p<<1)
#define rs (p<<1|1)
#define mid (((tr-tl)>>1)+tl)

using namespace std;

const int maxn=100005,maxm=100005,M=100000;
const int INF=1<<30;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int aBs(int x){
    return x<0?-x:x;
}

class segmentTree{
    private:
        struct TreeNode{
            int sum,num,len; // sum:此区间被整体覆盖了几次； num:被几个不相交线段覆盖； len: 被覆盖总长度；
            bool lflag,rflag; // 左右端点是否被覆盖
        };
        TreeNode tree[M+5];

    public:
        segmentTree(){
            memset(tree,0,sizeof(tree));
        }

        void push_up(int tl,int tr,int p){
            if (tree[p].sum){ // 如果当前区间已经被覆盖过
                tree[p].num=1;
                tree[p].len=tr-tl+1;
                    tree[p].lflag=tree[p].rflag=1;
            } else if (tl==tr){ // 如果区间只有 1 (叶节点)
                tree[p].len=0;
                tree[p].num=0;
                tree[p].lflag=tree[p].rflag=0;
            } else {
                tree[p].len=tree[ls].len+tree[rs].len;
                tree[p].num=tree[ls].num+tree[rs].num;
                if (tree[ls].rflag&&tree[rs].lflag) tree[p].num--;
                tree[p].lflag=tree[ls].lflag;
                tree[p].rflag=tree[rs].rflag;
            }
        }

        void update(int sl,int sr,int tl,int tr,int p,int delta){
            if (sl<=tl && tr<=sr){
                tree[p].sum+=delta;
                push_up(tl,tr,p);
                return;
            }
            if (sl<=mid  ) update(sl,sr,tl,mid,ls,delta);
            if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
            push_up(tl,tr,p);
        }

        int get_root_len(){
            return tree[1].len;
        }

        int get_root_num(){
            return tree[1].num;
        }
};

struct segment{
    int l,r,h,f;
};
segment make_segment(int l,int r,int h,int f){
    segment ret; ret.l=l; ret.r=r; ret.h=h; ret.f=f;
    return ret;
}
vector<segment> vec;
bool compare_h(segment aa,segment bb){
    return aa.h<bb.h;
}

int n,ans;
segmentTree t;

int main(){
    n=read();
    int maxx=-INF,minx=INF;
    for (int i=0;i<n;i++){
        int x1=read(),y1=read(),x2=read(),y2=read();
        maxx=max(maxx,max(x1,x2));
        minx=min(minx,min(x1,x2));
        vec.push_back(make_segment(x1,x2,y1, 1));
        vec.push_back(make_segment(x1,x2,y2,-1));
    }

    if (minx<0){
        for (int i=0;i<(int)vec.size();i++) vec[i].l+=-minx+1,vec[i].r+=-minx+1;
        maxx+=-minx;
    }

    sort(vec.begin(),vec.end(),compare_h);

    int last=0;
    for (int i=0;i<(int)vec.size();i++){
        t.update(vec[i].l,vec[i].r-1,1,maxx,1,vec[i].f);
        while (i+1<(int)vec.size() && vec[i].h==vec[i+1].h && vec[i].f==vec[i+1].f)
            i++,t.update(vec[i].l,vec[i].r-1,1,maxx,1,vec[i].f);
        ans+=aBs(t.get_root_len()-last);
        last=t.get_root_len();
        ans+=t.get_root_num()*2*(vec[i+1].h-vec[i].h);
    }
    printf("%d\n",ans);
    return 0;
}