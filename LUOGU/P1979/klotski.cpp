#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxnn=35,maxn=10005,maxe=50006;
const int flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int nn,mm,q;
int a[maxnn][maxnn];

int n;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int dist[maxn];
bool vis[maxn];

queue<int> que;

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
	// printf("%lld %lld %lld\n",x,y,z);
}

int make_status(int x,int y,int k){
	return ((x-1)*mm+y)+k*(nn*mm);
}

bool cando(int x,int y){
	if (x<1||y<1||x>nn||y>mm) return false;
	return a[x][y];
}

queue<pair<int,int> > qque;
bool vvis[maxnn][maxnn];
int ddist[maxnn][maxnn];

void BFS(int x,int y){
	memset(ddist,0x3f,sizeof(ddist));
	memset(vvis,0,sizeof(vvis));
	while (!qque.empty()) qque.pop();

	qque.push(make_pair(x,y)); ddist[x][y]=0; vvis[x][y]=true;
	while (!qque.empty()){
		pair<int,int> head=qque.front(); qque.pop();
		for (int i=0;i<4;i++){
			int xx=head.first+flg[i][0],yy=head.second+flg[i][1];
			if (cando(xx,yy) && !vvis[xx][yy]){
				vvis[xx][yy]=true,ddist[xx][yy]=ddist[head.first][head.second]+1;
				qque.push(make_pair(xx,yy));
			}
		}
	}
}

#define ni (i+flg[k][0])
#define nj (j+flg[k][1])

#define nni (i+flg[t][0])
#define nnj (j+flg[t][1])

void prebuild(){
	n=nn*mm*4;

	for (int i=1;i<=nn;i++)
		for (int j=1;j<=mm;j++) if (cando(i,j))
			for (int k=0;k<4;k++) if (cando(ni,nj)){
				add_edge(make_status(i,j,k),make_status(ni,nj,(k+2)%4),1);
				a[i][j]=0; BFS(ni,nj); a[i][j]=1;
				for (int t=0;t<4;t++) if (t!=k && cando(nni,nnj) && ddist[nni][nnj]<INF){
					add_edge(make_status(i,j,k),make_status(i,j,t),ddist[nni][nnj]);
				}
			}
}

void SPFA(int s){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	while (!que.empty()) que.pop();

	dist[s]=0; vis[s]=true; que.push(s);
	while (!que.empty()){
		int head=que.front(); que.pop(); vis[head]=false;
		for (int i=lnk[head];i;i=nxt[i]) if (dist[head]+w[i] < dist[to[i]]){
			dist[to[i]]=dist[head]+w[i];
			if (!vis[to[i]]) que.push(to[i]),vis[to[i]]=true;
		}
	}
}

signed main(){
	// freopen("testdata.in","r",stdin);
	// freopen("my.out","w",stdout);

	nn=read(); mm=read(); q=read();
	for (int i=1;i<=nn;i++)
		for (int j=1;j<=mm;j++)
			a[i][j]=read();
	
	prebuild();

	while (q--){
		int ex=read(),ey=read(),sx=read(),sy=read(),tx=read(),ty=read();
		if (sx==tx && sy==ty) {printf("0\n"); continue;}
		if (!cando(sx,sy) || !cando(ex,ey) || !cando(tx,ty)) {printf("-1\n");continue;}
		int ans=INF;
		for (int k=0;k<4;k++) if (cando(sx+flg[k][0],sy+flg[k][1])){
			a[sx][sy]=0; BFS(ex,ey); a[sx][sy]=1;
			int snum=ddist[sx+flg[k][0]][sy+flg[k][1]];
			if (snum==-1) continue;
			SPFA(make_status(sx,sy,k));
			for (int t=0;t<4;t++) if (cando(tx+flg[t][0],ty+flg[t][1])){
				ans=min(ans,snum+dist[make_status(tx,ty,t)]);
			}
		}
		printf("%lld\n",(ans>=INF)?-1:ans);
	}

	return 0;
}