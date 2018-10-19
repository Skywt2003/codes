#include<cstdio>
#include<cstring>
#include<iostream>

#define int long long
using namespace std;

const int tt=19260817;
const int maxn=30,maxe=2*maxn;
int n,m,a[maxn];
int tot=0,lnk[maxn],son[maxe],nxt[maxe];
bool vis[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void DFS(int x,int s){
	vis[x]=true;
	for (int i=lnk[x];i;i=nxt[i]) if ((!vis[son[i]])&&(((1<<son[i])&s))) DFS(son[i],s);
}

namespace SubTask2{
	const int maxn=3333+10,maxe=2*maxn;
	int tot=0,lnk[maxn],son[maxe],nxt[maxe];
	struct vertex{
		int nxt,pre;
	}v[maxn];
	int head,tail;

	inline void add(int x,int y){
		tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
	}

	inline void init(){
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			add(x,y);add(y,x);
		}
		head=-1;
		for (int i=1;i<=n;i++) if (nxt[lnk[i]]==0){
			head=i;
			break;
		}
		int lst=-1,now=head;
		for (int i=1;i<n;i++){
			v[now].pre=lst;
			for (int j=lnk[now];j;j=nxt[j]) if (son[j]!=lst){
				v[now].nxt=son[j];
				break;
			}
			lst=now;
			now=v[now].nxt;
		}
		v[now].pre=lst;v[now].nxt=-1;
		tail=now;
	}

	signed main(){
		init();
		int ans=0;
		for (int i=head;i!=-1;i=v[i].nxt){
			int minnum=1<<30,maxnum=-(1<<30);
			for (int j=i;j!=-1;j=v[j].nxt){
				minnum=min(minnum,a[j]);
				maxnum=max(maxnum,a[j]);
				if (maxnum-minnum==m) ans++; else
				if (maxnum-minnum>m) break;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
}

signed main(){
	freopen("lkf.in","r",stdin);
	freopen("lkf.out","w",stdout);
	n=read();m=read();
	if (n>22) return SubTask2::main();
	for (int i=0;i<n;i++) a[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x-1,y-1);add(y-1,x-1);
	}
	int s=1<<n,ans=0;
	for (int i=1;i<s;i++){
		int minnum=1<<30,maxnum=-(1<<30);
		for (int j=0;j<n;j++) if (i&(1<<j)){
			minnum=min(minnum,a[j]);
			maxnum=max(maxnum,a[j]);
		}
		if (maxnum-minnum!=m) continue;
		memset(vis,0,sizeof(vis));
		for (int j=0;j<n;j++) if (i&(1<<j)){
			DFS(j,i);
			break;
		}
		bool flg=true;
		for (int j=0;j<n;j++) if ((i&(1<<j))&&(vis[j]==false)) {flg=false;break;}
		ans+=flg;
	}
	printf("%lld\n",ans);
	return 0;
}