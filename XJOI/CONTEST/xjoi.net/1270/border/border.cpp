#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5e5+5;
const int tt=1e9+7;

int n,m;
int a[maxn];
int sum[maxn],suf[maxn],fin[maxn];

int qsm2[maxn],pre[maxn];

int fa[maxn];

int getfa(int x){
	return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
}

void merge(int x,int y){
	fa[x]=y; pre[y]=pre[x];
	int len=x-pre[x];
	if (len>30 && sum[y]>0 || sum[x]+(sum[y]<<len)>tt) sum[y]=tt; else
	sum[y]=sum[x]+(sum[y]<<len);
}

struct query{
	int x,y,ans,id;
}q[maxn];

bool compare_query_y(query aa,query bb){
	return aa.y < bb.y;
}
bool compare_query_id(query aa,query bb){
	return aa.id < bb.id;
}

void pre_build(){
	qsm2[0]=1;
	for (int i=1;i<=n;i++)
		qsm2[i]=qsm2[i-1]*2%tt,
		pre[i]=i-1,
		sum[i]=a[i],
		fa[i]=i;
	for (int i=n;i>=1;i--) suf[i]=(suf[i+1]*2%tt+a[i]+tt)%tt;
}

int get_part(int x,int y){
	return (suf[x] - suf[y+1]*qsm2[y-x+1]%tt + tt)%tt;
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) q[i].x=read(),q[i].y=read(),q[i].id=i;
	sort(q+1,q+1+m,compare_query_y);
	
	pre_build();
	int j=0;
	for (int i=1;i<=n;i++){
		while (pre[i] && sum[i]>=0) merge(pre[i],i);
		fin[i]=(fin[pre[i]]+get_part(pre[i]+1,i)*2%tt)%tt;
		while (q[j+1].y == i){
			j++; int x=getfa(q[j].x);
			q[j].ans=(fin[i]-fin[x]+get_part(q[j].x,x)+tt)%tt;
		}
	}

	sort(q+1,q+1+m,compare_query_id);

	for (int i=1;i<=m;i++) printf("%lld\n",q[i].ans);
	return 0;
}