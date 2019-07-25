#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

//int popcount(int x){
//	int ret=0;
//	while (x) ret+=x&1,x>>=1;
//	return ret;
//}

struct bitset{
	static const int maxn=150,maxm=30;
	int set[maxn];

	void clear(){ memset(set,0,sizeof(set)); }
	bool operator [](int index){ index--;return (set[index/maxm]>>index%maxm)&1; }
	void setValue(int index,int value){ index--; if (value) set[index/maxm]|=(int)1<<index%maxm; else set[index/maxm]&=~((int)1<<index%maxm); }
	void merge(bitset &b){for (int i=0;i<maxn;i++) set[i]&=b.set[i];}
	int count(){
		int ret=0;
		for (int i=0;i<maxn;i++) ret+=__builtin_popcount(set[i]);
//		for (int i=0;i<maxn;i++) ret+=popcount(set[i]);
		return ret;
	}
}defalt;

const int maxn=2005,maxe=40005;

int n,m;
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
int deep[maxn],fa[maxn],fae[maxn];
struct Path{
	int x,y,feg;
};
vector<Path> vec;

void addEdge(int x,int y){
	tot++;to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

bool cmp(Path aa,Path bb){
	return deep[aa.x]>deep[bb.x];
}

void buildTree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		deep[to[i]]=deep[x]+1; fa[to[i]]=x,fae[to[i]]=i;
		buildTree(to[i]);
	}
}

signed main(){
	for (;;){
		n=read();m=read();
		if (n==0 && m==0) break;
		tot=0;
		memset(lnk,0,sizeof(lnk));
		memset(nxt,0,sizeof(nxt));
		memset(to,0,sizeof(to));
		memset(deep,0,sizeof(deep));
		memset(fa,0,sizeof(fa));
		memset(fae,0,sizeof(fae));
		m-=n-1;
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			addEdge(x,y);addEdge(y,x);
		}
		vec.clear(); defalt.clear();
		for (int i=1;i<=m;i++){
			int x=read(),y=read();
			vec.push_back((Path){x,y,0});
		}
		
		deep[1]=1;
		buildTree(1);
		for (int i=0;i<vec.size();i++) if (deep[vec[i].x]>deep[vec[i].y]) swap(vec[i].x,vec[i].y);
		sort(vec.begin(),vec.end(),cmp);

		bitset now;
		for (int i=0;i<vec.size();i++){
			now.clear();
			int x=vec[i].y;
			while (fa[x]!=vec[i].x) now.setValue(fae[x],1),x=fa[x];
			now.setValue(fae[x],1); vec[i].feg=fae[x];
			now.merge(defalt);
			if (now.count()) continue;
//			printf("Seted value: %lld\n",vec[i].feg);
			defalt.setValue(vec[i].feg,1);
		}
		printf("%d\n",defalt.count());
	}
	return 0;
}
