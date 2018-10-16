#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<stack>
#include<cassert>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mem(x,y) memset(x,y,sizeof x)
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
const int INF=2e9;
const db eps=1e-12;
template<typename T>
inline void read(T &x) {
  x=0; int f=1; char ch=getchar();
  while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
  while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
  x*=f;
}
//==========================head template==========================
const int N=1000010;
int n;
ll f[N][2],len[N];
int to[N<<1],nxt[N<<1],head[N],lst; ll c[N<<1];
inline void adde(int x,int y,int z) {
  nxt[++lst]=head[x]; to[lst]=y; c[lst]=z; head[x]=lst;
}
inline void DP(int x,int fa) {
  for(int i=head[x];i;i=nxt[i])
    if(to[i]!=fa) {
      DP(to[i],x); len[x]=max(len[x],len[to[i]]+c[i]);
      f[x][0]+=f[to[i]][0]+c[i]*2;
      f[x][1]+=min(f[to[i]][0]-len[to[i]]+c[i],f[to[i]][1]+2*c[i]);
    }
}
signed main() {
  read(n);
  for(int i=1;i<n;i++) {
    int x,y,z; read(x); read(y); read(z);
    adde(x,y,z); adde(y,x,z);
  }
  DP(1,0);
  printf("%lld\n",f[1][1]);
  return 0;
}