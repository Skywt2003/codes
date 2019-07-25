#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

vector<int> readLineData(){
	vector<int> ret;ret.clear();
	char tools[10000];
	memset(tools,0,sizeof(tools));
	cin.getline(tools,10000);
	int ulen=0,tool;
	while (sscanf(tools+ulen,"%lld",&tool)==1){
		ret.push_back(tool);
	    if (tool==0) ulen++; else while (tool) tool/=10,ulen++;
		ulen++;
	}
	return ret;
}

const int maxn=105,maxe=1004;
const int INF=(int)1<<60;
int n,m,s,t;
int tot=-1,lnk[maxn],nxt[maxe],to[maxe],w[maxe],cur[maxn];
int deep[maxn];
int p[maxn],c[maxn];
vector<int> tools[maxn];
queue<int> que;
int ans=0,sum=0,used[maxn];

void addEdge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

bool BFS(){
	memset(deep,0,sizeof(deep));
	while (!que.empty()) que.pop();
	que.push(s);deep[s]=1;
	while (!que.empty()){
		int head=que.front();que.pop();
		for (int i=lnk[head];i!=-1;i=nxt[i]) if (w[i]>0 && deep[to[i]]==0) deep[to[i]]=deep[head]+1,que.push(to[i]);
	}
	return deep[t];
}

int DFS(int x,int now){
	if (x==t) return now;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (w[i]>0 && deep[to[i]]==deep[x]+1){
		int nxtd=DFS(to[i],min(now,w[i]));
		if (nxtd>0){
			w[i]-=nxtd;
			w[i^1]+=nxtd;
			return nxtd;
		}
	}
	return 0;
}

int Dinic(){
	n+=m+2;
	int ret=0;
	while (BFS()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(s,INF)) ret+=now;
	}
	n-=m+2;
	return ret;
}

void buildGraph(int x){
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	tot=-1;
	for (int i=1;i<=m;i++) addEdge(s,n+i,p[i]),addEdge(n+i,s,0);
	for (int i=1;i<=m;i++)
		for (int j=0;j<tools[i].size();j++)
			addEdge(n+i,tools[i][j],INF),addEdge(tools[i][j],n+i,0);
	for (int i=1;i<=n;i++) if (i!=x) addEdge(i,t,c[i]),addEdge(t,i,0);
}

void printData(){
	printf("%lld %lld\n",m,n);
	for (int i=1;i<=m;i++){
		printf("%lld ",p[i]);
		for (int j=0;j<tools[i].size();j++) printf("%lld ",tools[i][j]);
		printf("\n");
	}
	for (int i=1;i<=n;i++) printf("%lld ",c[i]);
	printf("\n");
}

signed main(){
	m=read();n=read();
	for (int i=1;i<=m;i++){
		p[i]=read();sum+=p[i];
		tools[i]=readLineData();
	}
	for (int i=1;i<=n;i++) c[i]=read();
	s=n+m+1; t=n+m+2;
	
//	printData();
	
	buildGraph(-1);
	ans=Dinic();
//	printf("First Dinic finished!\n");
	for (int i=1;i<=n;i++){
		buildGraph(i);
		int now=Dinic();
		if (ans-now == c[i]) used[i]=true;
	}
	for (int i=1;i<=m;i++){
		bool cando=true;
		for (int j=0;j<tools[i].size();j++) if (!used[tools[i][j]]) {cando=false;break;}
		if (cando) printf("%lld ",i);
	}
	printf("\n");
	for (int i=1;i<=n;i++) if (used[i]) printf("%lld ",i);
	printf("\n%lld\n",sum-ans);
	return 0;
}
