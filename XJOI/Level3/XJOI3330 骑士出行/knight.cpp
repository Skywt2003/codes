#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=305,maxv=10005,flg[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int n,x_1,y_1,x_2,y_2,ans[maxn][maxn],INF;
struct WT{
	int x,y;
}que[maxv];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool check(int x,int y){
	if (x<0||y<0||x>=n||y>=n) return false;
	return true;
}
inline void BFS(){
	int head=0,tail=1;
	que[tail].x=x_1;que[tail].y=y_1;ans[x_1][y_1]=0;
	while (head!=tail){
		head=(head+1)%maxv;
		int xx=que[head].x,yy=que[head].y;
		for (int i=0;i<8;i++) if (check(xx+flg[i][0],yy+flg[i][1])&&ans[xx][yy]+1<ans[xx+flg[i][0]][yy+flg[i][1]]){
			tail=(tail+1)%maxv;
			que[tail].x=xx+flg[i][0];que[tail].y=yy+flg[i][1];
			ans[xx+flg[i][0]][yy+flg[i][1]]=ans[xx][yy]+1;
		}
	}
}
int main(){
	memset(ans,63,sizeof(ans));
	INF=ans[0][0];
	n=read();
	x_1=read();y_1=read();
	x_2=read();y_2=read();
	BFS();
	printf("%d\n",ans[x_2][y_2]);
	return 0;
}
