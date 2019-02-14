#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=205,INF=1e9;
int n;
char a[maxn];
bool vis[maxn];

signed main(){
	n=read();
	scanf("%s",a+1);
	sort(a+1,a+1+n);
	sort(a+n+1,a+2*n);
	memset(vis,0,sizeof(vis));
	bool flg=true;
	for (int i=1;i<=n;i++){
		int minv=INF,k=-1;
		for (int j=n+1;j<=n*2;j++) if (!vis[j] && a[j]<minv){
			minv=a[j];k=j;
		}
		if (minv>=a[i]) {flg=false;break;} else vis[k]=true;
	}
	if (flg) {printf("YES\n");return 0;}

	memset(vis,0,sizeof(vis));
	flg=true;
	for (int i=1;i<=n;i++){
		int maxv=-INF,k=-1;
		for (int j=n+1;j<=n*2;j++) if (!vis[j] && a[j]>maxv){
			maxv=a[j];k=j;
		}
		if (maxv<=a[i]) {flg=false;break;} else vis[k]=true;
	}
	if (flg) {printf("YES\n");return 0;}
	printf("NO\n");
	return 0;
}