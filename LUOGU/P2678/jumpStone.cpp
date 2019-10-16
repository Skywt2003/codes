#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=50005;

int l,n,m,d[maxn];
int ans=0;

#define mid (((R-L)>>1)+L)

bool check(int x){
	int cnt=0,lst=0;
	for (int i=1;i<=n;i++) (d[i]-d[lst]<x)?cnt++:lst=i;
	#ifdef EBUG
		printf("Checking x=%lld: cnt=%lld\n",x,cnt);
	#endif
	return cnt<=m;
}

int L,R;

signed main(){
	l=read(); n=read(); m=read();
	for (int i=1;i<=n;i++) d[i]=read();
	d[++n]=l;

	L=0,R=l;
	while (L<=R) check(mid)?ans=mid,L=mid+1:R=mid-1;

	printf("%lld\n",ans);
	return 0;
}