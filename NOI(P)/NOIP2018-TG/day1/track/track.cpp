#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005,maxe=2*maxn;
int n,m,ans=0;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int fa[maxn],deep[maxn];
bool flg=true;
int L=0,R=0;

inline void add_edge(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]) fa[son[i]]=x,deep[son[i]]=deep[x]+1,build_tree(son[i]);
}

namespace Subtask1{ // For m=1 / 20pts
	inline pair<int,int> DFS(int x,int lst){
		pair<int,int> ret=make_pair(x,0);
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=lst){
			pair<int,int> now=DFS(son[i],x);
			now.second+=w[i];
			if (now.second > ret.second) ret=now;
		}
		return ret;
	}
	
	int main(){
		pair<int,int> p1=DFS(1,-1);
		pair<int,int> p2=DFS(p1.first,-1);
		printf("%d\n",p2.second);
		return 0;
	}
}

namespace Subtask2{ // For bi=ai+1 (Lian) / ex 10pts
	int dst[maxn],cnt=0;
	pair<int,int> v[maxn*maxn];

	inline bool cmp(pair<int,int> aa,pair<int,int> bb){
		return (aa.second<bb.second)||(aa.second==bb.second && aa.first<bb.first);
	}

	inline bool check(int x){
		cnt=0;
		for (int i=1;i<=n;i++){
			for (int j=n;j>i && dst[j]-dst[i]>=x;j--){
				v[++cnt]=make_pair(i,j);
			}
		}
		std::sort(v+1,v+1+cnt,cmp);
		int ret=0,lst=0;
		for (int i=1;i<=cnt;i++) if (v[i].first>=lst) lst=v[i].second,ret++;
		return ret>=m;
	}
	
	inline void build_dist(int x){
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]==x+1) dst[son[i]]=dst[x]+w[i],build_dist(son[i]);
	}

	int main(){
		build_dist(1);
		while (L<=R){
			int mid=((R-L)>>1)+L;
			if (check(mid)) ans=mid,L=mid+1; else R=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
}

namespace Subtask3{ // For ai=1 (Ju Flower Graph) / ex 5pts
// F***, this part is wrong!
	inline bool cmp(int x,int y){
		return x>y;
	}
	
	int main(){
		vector<int> vec;vec.clear();
		for (int i=1;i<=tot;i+=2) vec.push_back(w[i]);
		for (int i=1;i<=tot;i+=2){
			for (int j=i+2;j<=tot;j+=2){
				vec.push_back(w[i]+w[j]);
			}
		}
		std::sort(vec.begin(),vec.end(),cmp);
		printf("%d\n",vec[m-1]);
		return 0;
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		if (y!=x+1) flg=false;
		add_edge(x,y,z);add_edge(y,x,z);R+=z;
	}
	build_tree(1);
	if (m==1) return Subtask1::main();
	else if (flg) return Subtask2::main(); else
	return Subtask3::main();
	printf("%d\n",ans);
	return 0;
}
