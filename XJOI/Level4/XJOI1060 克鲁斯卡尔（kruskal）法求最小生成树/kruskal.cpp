#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005,maxe=200005;
struct SidesData{
	int a,b;
	long long w;
}e[maxe];
int n,m,cnt=0,fa[maxn];
long long ans=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool cmp(SidesData aa,SidesData bb){
	return aa.w<bb.w;
}
inline int getfa(int x){
	if (fa[x]==x) return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++) e[i].a=read(),e[i].b=read(),e[i].w=(long long)read();
	sort(e+1,e+1+m,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;(i<=m)&&(cnt<=n-1);i++){
		int fx=getfa(e[i].a),fy=getfa(e[i].b);
		if (fx==fy) continue;
		fa[fx]=fy;ans+=(long long)e[i].w;cnt++;
	}
	printf("%lld\n",ans);
	return 0;
}
