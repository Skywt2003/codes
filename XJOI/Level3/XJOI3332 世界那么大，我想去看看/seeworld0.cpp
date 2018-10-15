#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=30,flg[8][2]={{2,-1},{2,1},{1,-2},{1,2},{-1,-2},{-1,2},{-2,1},{-2,-1}};
int n,m,vis[maxn][maxn],wkd=0;
string ans;
bool alflg=true;
inline bool check(int x,int y){
	if (x<1||y<1||x>n||y>m) return false;
	return true;
}
inline void DFS(int x,int y){
	if (alflg==false) return;
	bool cgd=false;
	if (vis[x][y]==0) wkd++,vis[x][y]=1,cgd=1;
	ans+=(n-x+'A');ans+=(y+'0');
	if (wkd==n*m){
		alflg=false;return;
	}
	for (int i=0;i<8;i++) if (check(x+flg[i][0],y+flg[i][1])&&vis[x+flg[i][0]][y+flg[i][1]]==0){
		DFS(x+flg[i][0],y+flg[i][1]);
		return; 
	} 
//	for (int i=0;i<8;i++) if (check(x+flg[i][0],y+flg[i][1])&&vis[x+flg[i][0]][y+flg[i][1]]==1) DFS(x+flg[i][0],y+flg[i][1]);
	if (cgd&&alflg){
		vis[x][y]=0;wkd--;ans.erase(ans.length()-2,2);
	}
}
int main(){
	scanf("%d%d",&m,&n);
	ans="";
	DFS(n,1);
	if (ans.length()==0) printf("impossible\n"); else cout<<ans;
	return 0;
}
