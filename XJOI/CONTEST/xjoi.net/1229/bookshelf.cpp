#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=80005;

int n,m;

class indexTree{
    private:
        int tree[3*maxn];
    
        int lowbit(int x){
            return x&(-x);
        }
    public:
        void update(int x,int delta){
            while (x<=3*n) tree[x]+=delta,x+=lowbit(x);
        }

        int query(int x){
            int ret=0;
            while (x) ret+=tree[x],x-=lowbit(x);
            return ret;
        }
};

indexTree t;
int head=n+1,tail=2*n;
int pos[maxn];

signed main(){
    n=read();m=read();
    for (int i=n+1;i<=n*2;i++){
        int x=read();
        t.update(i,x); pos[x]=i;
    }

    while (m--){
        int opt=read();
        if (opt==1){
            int x=read();  t.update(pos[x],-x);
            pos[x]=--head; t.update(pos[x],x);
        } else if (opt==2){
            int x=read();  t.update(pos[x],-x);
            pos[x]=++tail; t.update(pos[x],x);
        } else if (opt==3){
            int s=read(),t=read();
            if (t==0) continue;
            if (t==-1){
                // To be continued... (???)
            }
        }
    }
}