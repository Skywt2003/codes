#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
int n;
int a[maxn],b[maxn];
int ans[maxn];
bool flg=false;

inline void DFS(int step){
	if (step==n){
		flg=true;
		return;
	}
	if (flg) return;
	for (int i=0;i<=3;i++){
		if ((i|ans[step])==a[step+1] && (i&ans[step])==b[step+1]){
			ans[step+1]=i;
			DFS(step+1);
		}
	}
}

signed main(){
	n=read();n--;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=0;i<=3;i++){
		ans[0]=i;
		DFS(0);
		if (flg) break;
	}
	if (!flg) printf("NO\n"); else {
		printf("YES\n");
		for (int i=0;i<=n;i++) printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}