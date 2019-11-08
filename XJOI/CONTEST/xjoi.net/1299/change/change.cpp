#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=10005;

int n,d[maxn];
int to[maxn];
int ans=0;

int blt[maxn],tot=0;
int rbr[maxn];

void find_loop(int x){
	int now=x; blt[now]=++tot; rbr[tot]=x; now=to[now];
	while (now!=x) blt[now]=tot,rbr[tot]=max(rbr[tot],now),now=to[now];
}

int abbs(int x){
	return (x<0)?-x:x;
}

signed main(){
	n=read();
	for (int i=2;i<=n;i++) d[i]=read();
	for (int i=1;i<=n;i++) to[i]=read();
	
	for (int i=1;i<=n;i++) if (!blt[i]) find_loop(i);
	
	while (to[n]==n) n--;
	
	for (int i=1;i<=n;i++) ans+=abbs(d[to[i]]-d[i]);
	int now=1;
	for (int i=1;i<=n;i++){
		if (i>now) ans+=2*(d[i]-d[now]);
		now=max(now,rbr[blt[i]]);
	}
	
	printf("%lld\n",ans);
	return 0;
}
