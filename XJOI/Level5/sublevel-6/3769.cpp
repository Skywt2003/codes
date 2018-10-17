#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long

const int maxn=305;

int n,m,INF;
int f[maxn][maxn],ans[maxn][maxn];
int p[maxn];

struct edge{
	int x,y,w;
};
vector<edge> e;

struct vertex{
	int x,id;
};
vector<vertex> v;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool compare(vertex aa,vertex bb){
	return aa.x<bb.x;
}

signed main(){
	n=read();m=read();
	for (int i=0;i<m;i++) e.push_back((edge){read(),0,0});
	for (int i=0;i<m;i++) e[i].y=read();
	for (int i=0;i<m;i++) e[i].w=read();
	for (int i=0;i<n;i++) v.push_back((vertex){read(),i});

	memset(ans,0x3f,sizeof(ans));INF=ans[0][0];
	memset(f,0x3f,sizeof(f));
	for (int i=0;i<n;i++) f[i][i]=ans[i][i]=0,p[i]=v[i].x;
	for (int i=0;i<m;i++) f[e[i].x][e[i].y]=f[e[i].y][e[i].x]=e[i].w;

	sort(v.begin(),v.end(),compare);
	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++) if (i!=v[k].id)
			for (int j=0;j<n;j++) if (i!=j&&v[k].id!=j)
				f[i][j]=min(f[i][j],max(f[i][v[k].id],f[v[k].id][j]));
		for (int i=0;i<n;i++) if (p[i]<=v[k].x)
			for (int j=0;j<n;j++) if (i!=j && p[j]<=v[k].x && f[i][j]!=INF)
				ans[i][j]=min(ans[i][j],f[i][j]*v[k].x);
	}
	int ans_tot=0;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			ans_tot+=ans[i][j];
	printf("%lld\n",ans_tot);
	return 0;
}