#include<bits/stdc++.h>

#define int long long

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;

int T,n,k;
char a[maxn];
int f[maxn];

void init(){
	memset(f,0,sizeof(f));
}

signed main(){
	T=read();
	while (T--){
		init();

		n=read(),k=read();
		scanf("%s",a+1);

		memset(f,0x3f,sizeof(f)); f[0]=0;
		for (int i=1;i<=n;i++){
			f[i]=f[i-1]+i;
			for (int j=max(0ll,i-k);j<=min(n,i+k);j++) if (a[j]=='1')
				f[i]=min(f[i],f[max(0ll,j-k-1)]+j);
		}

		printf("%lld\n",f[n]);
	}
	return 0;
}