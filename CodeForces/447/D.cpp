#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxn=1005;

int n,m,k,p;
int a[maxn][maxn];
int dt1=0,dt2=0;

priority_queue <int> heap1,heap2;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();m=read();k=read();p=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		a[i][j]=read();
	
	while (!heap1.empty()) heap1.pop();
	while (!heap2.empty()) heap2.pop();

	for (int i=1;i<=n;i++){
		int now_sum=0;
		for (int j=1;j<=m;j++) now_sum+=a[i][j];
		heap1.push(now_sum);
	}
	for (int i=1;i<=m;i++){
		int now_sum=0;
		for (int j=1;j<=n;j++) now_sum+=a[j][i];
		heap2.push(now_sum);
	}

	int ans=0;
	for (int i=1;i<=k;i++){
		int x1=heap1.top(),x2=heap2.top();
		if (x1-dt1<x2-dt2){
			ans+=x2-dt2;
			heap2.pop();heap2.push(x2-p*n);
			dt1+=p;
		} else {
			ans+=x1-dt1;
			heap1.pop();heap1.push(x1-p*m);
			dt2+=p;
		}
	}

	printf("%lld\n",ans);
	return 0;
}
