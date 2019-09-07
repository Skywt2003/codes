#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=15;
string a,b;
int n,num;
int ans=0;
int c[255][255];

queue<pair<string,int> > que;

void BFS(){
    while (!que.empty()) que.pop();
    que.push(make_pair(a,0)); ans+=(a==b);
    while (!que.empty()){
        pair<string,int> head=que.front(); que.pop();
        pair<string,int> nxt;
        for (int i=0;i<n;i++)
            for (char to='a';to<='c';to++){
                int now_cost=c[head.first[i]][to];
                if (now_cost!=-1 && head.second+now_cost<=num){
                    nxt=head;
                    nxt.first[i]=to; nxt.second+=now_cost;
                    if (nxt.first==b) ans++;
                    que.push(nxt);
                }
            }
    }
}

signed main(){
    cin>>a>>b;
    n=a.length();

    memset(c,-1,sizeof(c));
    c['a']['b']=read(); c['b']['c']=read(); c['c']['a']=read();
    num=read();

    BFS();

    printf("%lld\n",ans);
    return 0;
}