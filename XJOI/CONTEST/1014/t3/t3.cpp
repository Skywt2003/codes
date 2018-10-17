
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

#define int long long

using namespace std;

const int maxn=3005;

int n,a[maxn],ans=0,tot=0;
int sum[maxn][maxn];
int apd[maxn][maxn]; // apd[i][j]: [i,j]之间出现了多少种

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int get_count(int k,int i,int j){
	if (i>j) return 0;
	return sum[k][j]-sum[k][i-1];
}

inline void build(){
	for (int i=0;i<=3000;i++)
		for (int j=1;j<=n;j++)
			sum[i][j]+=sum[i][j-1];
	
	bool vis[maxn];
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for (int j=i=1;j<=n;j++){
			apd[i][j]=apd[i][j-1]+1-vis[a[j]];
			vis[a[j]]=true;
		}
	}
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum[a[i]][i]++;
	build();
	for (int i=1;i<=n;i++) if (get_count(a[i],1,i-1)==0){
		for (int j=i+1;j<=n;j++) if ((a[i]!=a[j]) && (get_count(a[j],i+1,j-1)==0)){
			int kinds=apd[1][n]-apd[i][j];
			ans+=(apd[j+1][n]-((get_count(a[i],j+1,n)>0)?1:0)-((get_count(a[j],j+1,n)>0)?1:0))*(1<<(kinds-1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}