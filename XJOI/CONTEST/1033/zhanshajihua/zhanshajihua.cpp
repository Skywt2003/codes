#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

// #define int long long
using namespace std;

const int maxn=5000005;
const int INF=0x3f3f3f3f;

int n,m,a[maxn],L=0,R=0;
int ans1=INF,ans2=INF;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int check(int x){
	int num[4];num[1]=num[2]=num[3]=0;
	for (int i=0;i<n;i++) if (a[i]!=0 && a[i]-3*x <= 3) num[(a[i]-1)%3+1]++;

	int sum=num[1]*1 + num[2]*2 + num[3]*3,ret=num[1]*1 + num[2]*1 + num[3]*4;
	if (sum<m) return -1;
	for (int i=1;i<=num[3];i++) if (sum-3>=m) sum-=3,ret-=4; else break;
	for (int i=1;i<=num[1];i++) if (sum-1>=m) sum-=1,ret-=1; else break;
	for (int i=1;i<=num[2];i++) if (sum-2>=m) sum-=2,ret-=1; else break;
	
	return ret;
}

signed main(){
	n=read();m=read();
	for (int i=0;i<n;++i) a[i]=read(),R=max(R,a[i]);
	
	while (L<=R){
		int mid=((R-L)>>1)+L;
		int now=check(mid);
		if (now!=-1){
			ans1=mid;ans2=now;
			R=mid-1;
		} else L=mid+1;
	}

	if (ans1==INF) printf("Human Cannot Win Dog\n"); else printf("%d %d\n",ans1,ans2+ans1);
	return 0;
}