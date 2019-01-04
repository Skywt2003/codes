#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=215;
const int zero=101;
const int INF=1e7;
bool vis[maxn][maxn];
int x[5],y[5],xx[5],yy[5];

inline int myabs(int x){return x<0?-x:x;}

signed main(){
	int minx=INF,maxx=-INF,miny=INF,maxy=-INF;
	for (int i=0;i<4;i++) x[i]=read(),y[i]=read();
	for (int i=0;i<4;i++) xx[i]=read(),yy[i]=read(),minx=min(minx,xx[i]),miny=min(miny,yy[i]),maxx=max(maxx,xx[i]),maxy=max(maxy,yy[i]);
	for (int i=min(x[0],x[2]);i<=max(x[0],x[2]);i++){
		for (int j=min(y[0],y[2]);j<=max(y[0],y[2]);j++){
			vis[i+zero][j+zero]=true;
		}
	}
	int midx=((maxx-minx)>>1)+minx;
	for (int i=minx;i<=maxx;i++){
		int delta=myabs(i-midx);
		for (int j=miny+delta;j<=maxy-delta;j++){
			if (vis[i+zero][j+zero]){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}