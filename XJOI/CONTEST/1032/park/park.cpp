#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=4005;
int n,q,d[maxn],l[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();q=read();
	for (int i=1;i<=n;i++) d[i]=read();
	for (int i=1;i<=n;i++) l[i]=read();
	while (q--){
		int L=read(),R=read(),x=read();
		int now=x,ans=x;
		for (int i=L;i<=R;i++){
			now=min(now+d[i],l[i]);
			now=max(now,min(x+d[i],l[i]));
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}