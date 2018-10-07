/*
 * XJOI CONTEST1000 T4 wzz与zzy
 * 180919 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=25;
int n,m;
char s[maxn][maxn];

int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) cnt+=s[i][j]=='.';
	}
	cnt-=n+m-1;
	printf((cnt&1)?"wzz\n":"zzy\n");
	return 0;
}