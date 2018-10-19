#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdlib>

using namespace std;
#define int long long
const int maxn=15,maxe=30,maxlen=25;

int n,tp,q;
char s[maxn][maxlen];
char S[maxlen];
int a[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int last_ans=0;
int V,ans=-1;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace KMP{
	int next[maxn];

	inline void make_next(char *p){
		memset(next,0,sizeof(next));
		int len=strlen(p);
		next[0]=next[1]=0;
		int k=0;
		for (int j=1;j<len;j++){
			while (k && p[j]!=p[k]) k=next[k];
			if (p[j]==p[k]) next[j+1]=++k; else next[j+1]=0;
		}
	}

	inline vector<int> query(char *s,char *p){
		make_next(p);
		vector<int> ret;ret.clear();
		int k=0;
		int n=strlen(s),m=strlen(p);
		for (int j=0;j<n;j++){
			while (k && s[j]!=p[k]) k=next[k];
			if (s[j]==p[k]) k++;
			if (k==m) ret.push_back(j-m+2);
		}
		return ret;
	}
}

inline void DFS(int x,int sum,int fa){
	if (ans!=-1) return;
	if (x==V){
		ans=sum;
		return;
	}
	for (int i=lnk[x];i;i=nxt[i]) DFS(son[i],sum+a[son[i]]*KMP::query(S,s[son[i]]).size(),x);
}

signed main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	n=read();tp=read();
	for (int i=1;i<=n;i++) scanf("%s",s[i]);
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	q=read();
	while (q--){
		int op=read();
		if (op==1){
			int u_=read(),v_=read();
			int u=u_^(last_ans*tp);
			int v=v_^(last_ans*tp);
			V=v;
			scanf("%s",S);
			ans=-1;
			DFS(u,a[u]*KMP::query(S,s[u]).size(),-1);
			printf("%lld\n",ans);
			last_ans=ans;
		} else {
			int x_=read(),c_=read();
			int x=x_^(last_ans*tp);
			int c=c_^(last_ans*tp);
			a[x]=c;
		}
	}
	return 0;
	printf("Fuck YOU!!!\n");
}