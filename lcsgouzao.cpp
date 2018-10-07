/*
 * XJOI CONTEST1000 T3 LCS构造机
 * 180919 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

const int maxn=1005;
char s[3][maxn];
struct Edge{
	int x,y,w;
};
vector <Edge> a;

const int other[3][3]={{-1,2,1},
					   {2,-1,0},

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool compare(Edge aa,Edge bb){
	return aa.w<bb.w;
}

int main(){
	int x=read(),y=read(),z=read();
	a.push_back((Edge){0,1,x});
	a.push_back((Edge){1,2,y});
	a.push_back((Edge){2,0,z});
	sort(a.begin(),a.end(),compare);

	for (int i=1;i<=a[0].w;i++) s[a[0].x][i]=s[a[0].y][i]=(i&1)?'0':'1';
	if (a[1].x==a[0].x||a[1].y==a[0].x) for (int i=a[0].w+1;i<=a[1].w;i++) s[a[0].x][i]='0'; else for (int i=a[0].w+1;i<=a[2].w;i++) s[a[0].x][i]='0';
	if (a[1].x==a[0].y||a[1].y==a[0].y) for (int i=a[0].w+1;i<=a[1].w;i++) s[a[0].y][i]='1'; else for (int i=a[0].w+1;i<=a[2].w;i++) s[a[0].y][i]='1';
	
	int now=other[a[0].x][a[0].y];
	for (int j=1;j<=a[1].w;j++) s[now][j]=s[a[0].x][j];
	for (int j=a[1].w+1;j<=a[1].w+a[2].w;j++) s[now][j]=s[a[0].y][j-a[1].w];

	for (int i=0;i<3;i++){
		int nnow=strlen(s[i]+1);
		for (int j=1;j<=nnow;j++) putchar(s[i][j]);
		printf("\n");
	}
	return 0;
}