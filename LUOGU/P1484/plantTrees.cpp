#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=500005;
const int INF=(int)1<<60;

int n,k,val[maxn];
int pos[maxn],pre[maxn],nxt[maxn];

#define fa (p>>1)
#define ls (p<<1)
#define rs ((p<<1)|1)

class heap{
    private:
        int t[maxn],cnt;

    public:
        heap(){cnt=0;memset(t,0,sizeof(t));}

        int top(){return t[1];}

        void change_node(int p){
            while (ls<=n){
                int son=(rs>n || val[t[ls]]>val[t[rs]])?ls:rs;
                if (val[t[son]] > val[t[p]]) swap(pos[t[son]],pos[t[p]]),swap(t[son],t[p]); else break;
                p=son;
            }
        }

        void insert_node(int p){
            t[p]=cnt=pos[p]=p;
            while (fa>=1 && val[t[p]] > val[t[fa]]) swap(pos[t[p]],pos[t[fa]]),swap(t[p],t[fa]),p=fa;
        }
};

heap dui;

signed main(){
    n=read();k=read();
    for (int i=1;i<=n;i++) val[i]=read(),dui.insert_node(i),pre[i]=i-1,nxt[i]=i+1;

    int ans=0;
    while (k--){
        int now=dui.top();
        if (val[now]<0) break;
        ans+=val[now]; val[now]=val[pre[now]]+val[nxt[now]]-val[now];
        val[pre[now]]=-INF; dui.change_node(pos[pre[now]]);
        val[nxt[now]]=-INF; dui.change_node(pos[nxt[now]]);
        dui.change_node(1);
        pre[now]=pre[pre[now]]; nxt[now]=nxt[nxt[now]];
        nxt[pre[now]]=pre[nxt[now]]=now;
    }
    printf("%lld\n",ans);
    return 0;
}