#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int ans=1<<30,sum_line[5],sum_row[5];
bool vis[5][5],chg[5][5],anss[5][5];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void DFS(int x,int y,int sum){
	if (sum>ans) return;
	if (x==5){
		bool suc=true;
		for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++){
			int sn=sum_row[i]+sum_line[j]-chg[i][j];
			if (vis[i][j]-(sn%2)) {suc=false;return;}
		}
		if (suc){
			ans=sum;
			for (int i=1;i<=4;i++)
			for (int j=1;j<=4;j++) anss[i][j]=chg[i][j];
		}
		return;
	}
	int xn=x,yn=y;
	if (yn==4) xn++,yn=1; else yn++;
	sum_row[x]++;sum_line[y]++;chg[x][y]=1;
	DFS(xn,yn,sum+1);
	sum_row[x]--;sum_line[y]--;chg[x][y]=0;
	DFS(xn,yn,sum);
}
int main(){
	freopen("fridge.in","r",stdin);
	freopen("fridge.out","w",stdout);
	char ch=getchar();while (ch!='+'&&ch!='-') ch=getchar();
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++){
		vis[i][j]=ch=='+';
		if (i==4&&j==4) continue;
		ch=getchar();while (ch!='+'&&ch!='-') ch=getchar();
	}
	DFS(1,1,0);
	printf("%d\n",ans);
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++) if (anss[i][j]) printf("%d %d\n",i,j);
	return 0;
}
