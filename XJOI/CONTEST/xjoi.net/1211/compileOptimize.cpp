#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005,INF=1e9;

#define ls (p<<1)
#define rs ((p<<1)|1)
#define fa (p>>1)

int n,m;
int val[maxn],pre[maxn],nxt[maxn];
int pos[maxn];

class heap{
    private:
        int cnt,t[maxn];
    
    public:
        heap(){cnt=0; memset(t,0,sizeof(t));}

        int top(){return t[1];}

        void change_node(int p){
            while (ls<=n){
                int son=(rs>n||val[t[ls]]>=val[t[rs]])?ls:rs;
                if (val[t[son]]>val[t[p]]) swap(t[son],t[p]),swap(pos[t[son]],pos[t[p]]); else break;
                p=son;
            }
        }

        void insert_node(int p){
            t[p]=p;
            while (val[t[p]]>val[t[fa]] && p>1) swap(t[p],t[fa]),swap(pos[t[p]],pos[t[fa]]),p=fa;
        }
};

heap dui;

signed main(){
    n=read();m=read();
    if ((n>>1)<m){
        printf("Error!\n");
        return 0;
    }
    for (int i=1;i<=n;i++) val[i]=read(),pos[i]=i,dui.insert_node(i),pre[i]=i-1,nxt[i]=i+1;
    pre[1]=n; nxt[n]=1;

    int ans=0;
    while (m--){
        int now=dui.top();
        ans+=val[now]; val[now]=val[pre[now]]+val[nxt[now]]-val[now];
        val[pre[now]]=-INF; dui.change_node(pos[pre[now]]);
        val[nxt[now]]=-INF; dui.change_node(pos[nxt[now]]);
        dui.change_node(1);
        pre[now]=pre[pre[now]]; nxt[now]=nxt[nxt[now]];
        pre[nxt[now]]=nxt[pre[now]]=now;
    }
    printf("%lld\n",ans);
    return 0;
}