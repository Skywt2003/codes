#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define int long long
using namespace std;

const int maxn=1000005;

int n,cnt;
int a[maxn];
int fa[maxn],ls[maxn],rs[maxn],deep[maxn];
int root,ans=0;

struct node{
	int x,id;
	bool operator <(node b)const{
		return x>b.x;
	}
};
priority_queue <node> heap;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void DFS(int x){
	if (x==0) return;
	deep[ls[x]]=deep[rs[x]]=deep[x]+1;
	DFS(ls[x]);DFS(rs[x]);
}

signed main(){
	n=cnt=read();
	for (int i=1;i<=n;i++) a[i]=read(),heap.push((node){a[i],i});
	for (int i=1;i<n;i++){
		node now1=heap.top();heap.pop();
		node now2=heap.top();heap.pop();
		fa[now1.id]=fa[now2.id]=++cnt;
		ls[cnt]=now1.id;rs[cnt]=now2.id;
		heap.push((node){now1.x+now2.x,cnt});
	}
	for (int i=1;i<=cnt;i++) if (fa[i]==0) {root=i;break;}
	DFS(root);
	for (int i=1;i<=n;i++) ans+=a[i]*deep[i];
	// for (int i=1;i<=n;i++) printf("%lld ",deep[i]);
	printf("%lld\n",ans);
	return 0;
}