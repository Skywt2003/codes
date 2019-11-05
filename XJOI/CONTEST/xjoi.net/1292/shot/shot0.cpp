#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=25;
const int maxs=1048576+10;

const int tt=998244353;

int n,m;
int ans=0;
int x[maxn];

bool vis[maxs];

void DFS(int step,int s){
	if (step==m){
		if (vis[s]==false) {vis[s]=true;ans++;}
		return;
	}
	if ((s&(1<<x[step+1]))==0) return DFS(step+1,s|(1<<x[step+1]));
	
	for (int i=x[step+1]-1;i>=0;i--) if ((s&(1<<i))==0){
		DFS(step+1,s|(1<<i));
		break;
	}
	for (int i=x[step+1]+1;i<n;i++) if ((s&(1<<i))==0){
		DFS(step+1,s|(1<<i));
		break;
	}
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++) x[i]=read()-1;
	
	DFS(0,0);
	printf("%d\n",ans);
	return 0;
}
