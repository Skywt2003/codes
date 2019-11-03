#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=500005;

int n,a[maxn];

int xum=0;
int ans1=0,ans2=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),xum^=a[i];
	if (!xum){puts("lose");return 0;}

	for (int i=31;i>=0;i--) if (xum&(1<<i)){
		int now=0;
		for (int j=1;j<=n;j++) if (a[j]&(1<<i)){
			ans2=j; now=a[j];
			break;
		}
		now-=1<<i;
		for (int j=i-1;j>=0;j--) if (xum&(1<<j))
			now+=((now&(1<<j))?(-(1<<j)):(1<<j));
		ans1=a[ans2]-now;
		break;
	}
	printf("%d %d\n",ans1,ans2);
	a[ans2]-=ans1;
	for (int i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");
	return 0;
}