#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define int long long
using namespace std;

#define sqr(_) ((_)*(_))

const int maxn=55,N=50;
int n,m;
double ans=0.0;

struct town{
	int x,y,id;
	bool iscity;
};
vector<town> all_town;
town a[maxn],b[maxn];
town middle_town;

int fac[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int get_distance(town aa,town bb){
	return sqr(aa.x-bb.x)+sqr(aa.y-bb.y);
}

inline bool cmp(town aa,town bb){
	return get_distance(aa,middle_town) < get_distance(bb,middle_town);
}

inline void build_fact(){
	fac[0]=1;
	bool stop=false;
	for (int i=1;i<=N;i++){
		if (fac[i-1]>1e10 || fac[i-1]<0) stop=true;;
		fac[i]=stop?(1e10):(fac[i-1]*i);
	}
}

signed main(){
	build_fact();

	n=read();m=read();
	for (int i=1;i<=n;++i) a[i].x=read(),a[i].iscity=true,a[i].id=i;
	for (int i=1;i<=n;++i) a[i].y=read(),all_town.push_back(a[i]);
	for (int i=1;i<=m;++i) b[i].x=read(),b[i].iscity=false,a[i].id=i+n;
	for (int i=1;i<=m;++i) b[i].y=read(),all_town.push_back(b[i]);

	for (int i=1;i<=m;++i){
		middle_town=b[i];
		sort(all_town.begin(),all_town.end(),cmp);
		vector<town> now;now.clear();
		for (int j=0;j<all_town.size();++j){
			now.push_back(all_town[j]);
			if (all_town[j].iscity) break;
		}
		for (int j=1;j<now.size()-1;++j){
			double p=(double)fac[now[j].id-1]/(fac[now[j].id+1]);
			ans+=p*sqrt(get_distance(b[i],now[j]));
		}
		{
			double p=1.0/(now[now.size()-1].id+1);
			ans+=p*sqrt(get_distance(b[i],now[now.size()-1]));
		}
	}
	printf("%.15lf\n",ans);
	return 0;
}