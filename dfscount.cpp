/*
 * XJOI CONTEST1001 T6 dfs计数
 * 180920 By SkyWT
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

#define write(_) cout<<#_<<" = "<<_<<endl;

const int maxn=20;
int n,ans=0;
bool cnt[maxn][maxn],vis[maxn];

inline char read_ch(){
	char ch=getchar();
	while (ch!='N'&&ch!='Y') ch=getchar();
	return ch;
}

inline void DFS(int x,int count){
	vis[x]=true;
	bool flg=true;
	for (int i=1;i<=n;i++) if (cnt[x][i]&&(!vis[i])) DFS(i,count+1),flg=false;
	ans+=flg;
	vis[x]=false;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		cnt[i][j]=read_ch()=='Y';
	for (int i=1;i<=n;i++) DFS(i,0);
	printf("%d\n",ans);
	return 0;
}