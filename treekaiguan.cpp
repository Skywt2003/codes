/*
 * XJOI CONTEST1004 T4 树上开关
 * 180924 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55,maxe=105;
int n,ans=0;
int p[maxn];
char s1[maxn],s2[maxn];
int tot0=0,lnk0[maxn],nxt0[maxe],son0[maxe];
bool w0[maxe],imp[maxe];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],deep[maxn];
bool w[maxe];
bool vis[maxn];

struct node{
	int x,deep;
};
vector<node> a;

inline void add0(int x,int y,bool z,bool im){
	// printf("Build First Tree: %lld ==> %lld\n",x,y);
	tot0++;son0[tot0]=y;w0[tot0]=z;imp[tot0]=im;nxt0[tot0]=lnk0[x];lnk0[x]=tot0;
}

inline void add(int x,int y,bool z){
	// printf("Added two: %lld ==> %lld: %lld\n",x,y,z);
	tot++;son[tot]=y;w[tot+1>>1]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline bool compare(node aa,node bb){
	return aa.deep>bb.deep;
}

inline void make_new_graph(int x,int self,bool flag);

inline void build_graph(){
	for (int i=0;i<n-1;i++) add0(p[i],i+1,s1[i]=='1',s2[i]=='1');
	deep[0]=1;
	memset_clear(vis);
	make_new_graph(0,0,true);
	for (int i=0;i<n;i++) a.push_back((node){i,deep[i]});
	sort(a.begin(),a.end(),compare);
}

inline void make_new_graph(int x,int self,bool flag){
	// printf("Making new graph: X=%lld, self=%lld, flag=%lld\n",x,self,flag);
	for (int i=lnk0[x];i;i=nxt0[i]) if (!vis[son0[i]]){
		vis[son0[i]]=true;
		if (imp[i]) add(self,son0[i],w0[i]),add(son0[i],self,w0[i]),deep[son0[i]]=deep[self]+1;
		make_new_graph(son0[i],imp[i]?son0[i]:self, imp[i]?flag:(flag&w0[i]));
	}
}

inline void find_path(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (!w[i+1>>1]){
		w[i+1>>1]=true;
		find_path(son[i]);
		break;
	}
}

signed main(){
	n=read();
	for (int i=0;i<n-1;i++) p[i]=read();
	scanf("%s",s1);scanf("%s",s2);
	build_graph();
	// for (int i=0;i<n;i++) write_2(i,deep[i]);
	for (int i=0;i<n;i++){
		int now=a[i].x;
		bool flg=false;
		for (int j=lnk[now];j;j=nxt[j]) if (!w[j+1>>1]) {flg=true;break;}
		ans+=flg;
		if (flg) find_path(now);//,printf("Find path:%lld\n",now);
	}
	printf("%lld\n",ans);
	return 0;
}