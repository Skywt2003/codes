#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=55,maxv=200005,flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,xs,ys,xt,yt,fs,ans=-1;
bool a[maxn][maxn],vis[maxn][maxn][5];
struct StepData{
	int x,y,f,s;
}que[maxv];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int read_ch(){
	char ch=getchar();
	while (ch!='N'&&ch!='E'&&ch!='S'&&ch!='W') ch=getchar();
	if (ch=='N') return 0; else 
	if (ch=='E') return 1; else
	if (ch=='S') return 2; else 
	if (ch=='W') return 3;
}
inline bool check(int x,int y){
	if (x<1||y<1||x>=n||y>=m) return false;
	if (a[x][y]||a[x+1][y]||a[x][y+1]||a[x+1][y+1]) return false;
	return true;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	xs=read();ys=read();xt=read();yt=read();fs=read_ch();
	if ((xs==xt)&&(ys==yt)){printf("0\n");return 0;}
	if (check(xs,ys)==false){printf("-1\n");return 0;}
	int head=0,tail=1;
	que[tail].x=xs;que[tail].y=ys;que[tail].f=fs;que[tail].s=0;
	vis[xs][ys][fs]=1;
	while (head<=tail){
		head=(head+1)%maxv;
		int xx=que[head].x,yy=que[head].y,ff=que[head].f;
		if (xx==xt&&yy==yt){
			ans=que[head].s;
			break;
		}
		for (int i=1;i<=3;i++) if (check(xx+i*flg[ff][0],yy+i*flg[ff][1])){
			if (vis[xx+i*flg[ff][0]][yy+i*flg[ff][1]][ff]==false){
				tail=(tail+1)%maxv;
				que[tail].x=xx+i*flg[ff][0];que[tail].y=yy+i*flg[ff][1];que[tail].f=ff;
				que[tail].s=que[head].s+1;
				vis[xx+i*flg[ff][0]][yy+i*flg[ff][1]][ff]=1;
			}
		} else break;
		if (vis[xx][yy][(ff+1)%4]==false){
			tail=(tail+1)%maxv;
			que[tail].x=xx;que[tail].y=yy;que[tail].f=(ff+1)%4;
			que[tail].s=que[head].s+1;
			vis[xx][yy][(ff+1)%4]=1;
		}
		if (vis[xx][yy][(ff+3)%4]==false){
			tail=(tail+1)%maxv;
			que[tail].x=xx;que[tail].y=yy;que[tail].f=(ff+3)%4;
			que[tail].s=que[head].s+1;
			vis[xx][yy][(ff+3)%4]=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
