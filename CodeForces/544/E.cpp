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
int cost[maxn][maxn],ss[maxn][maxn],sc[maxn][maxn];
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
		for (int j=0;j<m;j++) cost[i][j]=read();
	}
	
	memset(f,63,sizeof(f));
	INF=f[0];
	int init_s=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			bool flg=true;
			for (int k=0;k<n;k++) if (k!=i && a[i][j]==a[k][j]){flg=false;break;}
			if (flg) {init_s+=1<<i;break;}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			for (int k=0;k<n;k++) if (k!=i && a[i][j]==a[k][j]){
				ss[i][j]+=1<<k;
				sc[i][j]+=cost[k][j];
			}
		}
	}
	f[init_s]=0;
	int alls=1<<n;
	for (int s=0;s<alls;s++) if (f[s]!=INF){
		for (int i=0;i<n;i++) if ((s&(1<<i))==0){
			int nxt_s=s+(1<<i);
			for (int j=0;j<m;j++){
				f[nxt_s]=min(f[nxt_s],f[s]+cost[i][j]);
			}

			for (int j=0;j<m;j++){
				nxt_s=(s+(1<<i))|ss[i][j];
				f[nxt_s]=min(f[nxt_s],f[s]+sc[i][j]);
			}
		}
	}
	printf("%lld\n",f[alls-1]);
	return 0;
}