#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=1005;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct point{
	int x,y;
};

int n;
vector<point> v1,v2;

inline bool cmp(point aa,point bb){
	return (aa.x<bb.x)||(aa.x==bb.x && aa.y<bb.y);
}

int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int xx=read(),yy=read();
		v1.push_back((point){xx,yy});
	}
	for (int i=1;i<=n;i++){
		int xx=read(),yy=read();
		v2.push_back((point){xx,yy});
	}
	sort(v1.begin(),v1.end(),cmp);
	sort(v2.begin(),v2.end(),cmp);
	printf("%d %d\n",v1[0].x+v2[n-1].x,v1[0].y+v2[n-1].y);
	return 0;
}