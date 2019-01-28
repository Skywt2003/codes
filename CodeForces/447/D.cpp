#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

#define int long long

const int maxn=1005,maxk=1000005;
const int INF=(int)1<<60;

int n,m,k,p;
int a[maxn][maxn];
int x[maxk],y[maxk];

priority_queue <int> heap;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();m=read();k=read();p=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	
	while (!heap.empty()) heap.pop();
	for (int i=1;i<=n;i++){
		int sum=0;
		for (int j=1;j<=m;j++) sum+=a[i][j];
		heap.push(sum);
	}
	for (int i=1;i<=k;i++){
		int now_top=heap.top();
		x[i]=x[i-1]+now_top;
		heap.pop();heap.push(now_top-m*p);
	}

	while (!heap.empty()) heap.pop();
	for (int i=1;i<=m;i++){
		int sum=0;
		for (int j=1;j<=n;j++) sum+=a[j][i];
		heap.push(sum);
	}
	for (int i=1;i<=k;i++){
		int now_top=heap.top();
		y[i]=y[i-1]+now_top;
		heap.pop();heap.push(now_top-n*p);
	}

	int ans=-INF;
	for (int i=0;i<=k;i++){
		ans=max(ans,x[i]+y[k-i]-(k-i)*i*p);
	}

	printf("%lld\n",ans);
	return 0;
}
