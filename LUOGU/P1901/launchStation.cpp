#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0' && ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1000005;

int n;
int height[maxn],power[maxn];

int stk[maxn],stk_top=0;
int sum[maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) height[i]=read(),power[i]=read();
	
	stk_top=0;
	for (int i=1;i<=n;i++){
		while (stk_top>0 && height[stk[stk_top]] < height[i]) stk_top--;
		if (stk_top>0) sum[stk[stk_top]]+=power[i];
		stk[++stk_top]=i;
	}
	
	stk_top=0;
	for (int i=n;i>=1;i--){
		while (stk_top>0 && height[stk[stk_top]] < height[i]) stk_top--;
		if (stk_top>0) sum[stk[stk_top]]+=power[i];
		stk[++stk_top]=i;
	}
	
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,sum[i]);
	printf("%lld\n",ans);
	return 0;
}

