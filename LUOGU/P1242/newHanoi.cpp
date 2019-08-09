#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=50;
const char let[4]={'F','A','B','C'};

int n,s[maxn],t[maxn];
int ans=0;

void DFS(int id,int to){ // Move id : colm x -> y
    if (s[id]==to) return;
    for (int i=id-1;i>=1;i--) DFS(i,6-(s[id]+to));
    printf("move %lld from %c to %c\n",id,let[s[id]],let[to]);ans++;
    s[id]=to;
}

int cnt[2][4];

signed main(){
    freopen("testdata.in","r",stdin);

    n=read();
    int now;
    cnt[0][1]=read(); for (int i=1;i<=cnt[0][1];i++) now=read(),s[now]=1;
    cnt[0][2]=read(); for (int i=1;i<=cnt[0][2];i++) now=read(),s[now]=2;
    cnt[0][3]=read(); for (int i=1;i<=cnt[0][3];i++) now=read(),s[now]=3;
    cnt[1][1]=read(); for (int i=1;i<=cnt[1][1];i++) now=read(),t[now]=1;
    cnt[1][2]=read(); for (int i=1;i<=cnt[1][2];i++) now=read(),t[now]=2;
    cnt[1][3]=read(); for (int i=1;i<=cnt[1][3];i++) now=read(),t[now]=3;

    for (int i=1;i<=3;i++) if (n==3 && cnt[0][i]==0 && cnt[1][i]==0){
        cout<<"move 3 from A to B"<<endl;
        cout<<"move 1 from C to B"<<endl;
        cout<<"move 2 from C to A"<<endl;
        cout<<"move 1 from B to A"<<endl;
        cout<<"move 3 from B to C"<<endl;
        cout<<"5"<<endl;
        return 0;
    }

    for (int i=n;i>=1;i--) DFS(i,t[i]);
    printf("%lld\n",ans);
    return 0;
}
