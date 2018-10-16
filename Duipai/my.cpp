#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1000005,maxe=2000005;
int n,fa[maxn],ans=0;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int mem[maxn][2];

inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]){
		fa[son[i]]=x;
		build_tree(son[i]);
	}
}

inline int make_sub(int x,bool got){
	if (mem[x][got]!=-1) return mem[x][got];
	int ret=0;
	vector<int> v1,v2;
	v1.clear();v2.clear();
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]){
		v1.push_back(make_sub(son[i],true)+w[i]);
		v2.push_back(make_sub(son[i],false));
	}
	if (!got){
		for (int i=0;i<v1.size();i++) ret+=max(v1[i],v2[i]);
	} else {
		int sum=0;
		for (int i=0;i<v1.size();i++) sum+=v2[i];
		for (int i=0;i<v1.size();i++) ret=max(ret,sum-v2[i]+v1[i]);
		ret=max(ret,sum);
	}
	return mem[x][got]=ret;
}

signed main(){
	memset(mem,255,sizeof(mem));
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
		ans+=2*z;
	}
	build_tree(1);
	ans-=make_sub(1,false);
	printf("%lld\n",ans);
	return 0;
}