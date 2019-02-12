#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=25,maxs=1048576+10;
int n,m,INF;
char a[maxn][maxn];
int cost[maxn][maxn];
int f[maxs];


inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();m=read();
	for (int i=0;i<n;i++) scanf("%s+1",a[i]);
	for (int i=0;i<n;i++){
		for (int j=1;j<=m;j++) cost[i][j]=read();
	}
	
	memset(f,63,sizeof(f));
	INF=f[0];
	int init_s=0;
	for (int i=0;i<n;i++){
		for (int j=1;j<=m;j++){
			bool flg=true;
			for (int k=0;k<n;k++) if (k!=i && a[i][j]==a[k][j]){flg=false;break;}
			if (flg) {init_s+=1<<i;break;}
		}
	}
	f[init_s]=0;
	int alls=1<<n;
	for (int s=0;s<alls;s++) if (f[s]!=INF){
		for (int i=0;i<n;i++) if ((s&(1<<i))==0){
			int nxt_s=s+(1<<i);
			for (int j=1;j<=m;j++){
				f[nxt_s]=min(f[nxt_s],f[s]+cost[i][j]);
			}

			int cost_now=0;
			for (int j=1;j<=m;j++){
				nxt_s=s;int sum=0,max_cost=0;
				for (int k=0;k<n;k++) if (a[k][j]==a[i][j]){
					if ((nxt_s&(1<<k))==0) nxt_s+=1<<k;
					sum+=cost[k][j];max_cost=max(max_cost,cost[k][j]);
				}
				f[nxt_s]=min(f[nxt_s],f[s]+sum-max_cost);
			}
		}
	}
	printf("%lld\n",f[alls-1]);
	return 0;
}