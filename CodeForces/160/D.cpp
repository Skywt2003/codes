#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
const int maxe=1e5+5;
int n,m;

struct edge{
	int x,y,w;
	int ans,id; // 1:none  2:at least one  3:all
}a[maxe];

bool cmp(edge aa,edge bb){
	return aa.w<bb.w;
}

bool cmp_id(edge aa,edge bb){
	return aa.id<bb.id;
}


namespace UniSet{
	int fa[maxn];

	void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i;
	}

	int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}
}

bool check(edge now,int aa,int bb){
	int fx=UniSet::getfa(now.x);
	int fy=UniSet::getfa(now.y);
	if (fx==aa && fy==bb) return true;
	if (fx==bb && fy==aa) return true;
	return false;
}

signed main(){
	n=read();m=read();
	UniSet::init(n);
	for (int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].w=read(),a[i].ans=1,a[i].id=i;
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m;){
		int j=i;
		int fx=UniSet::getfa(a[i].x),fy=UniSet::getfa(a[i].y);
		if (fx==fy) {i++;continue;}
		while (j+1<=m && a[j+1].w==a[i].w && check(a[j+1],fx,fy)) j++;
		if (j-i+1 == 1){
			a[i].ans=3;
			UniSet::fa[fx]=fy;
		} else {
			for (int k=i;k<=j;k++) a[k].ans=2;
			UniSet::fa[fx]=fy;
		}
		i=j+1;
	}

	sort(a+1,a+1+m,cmp_id);

	for (int i=1;i<=m;i++){
		if (a[i].ans==1) printf("none\n"); else
		if (a[i].ans==2) printf("at least one\n"); else
		if (a[i].ans==3) printf("any\n");
	}

	return 0;
}