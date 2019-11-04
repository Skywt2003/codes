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
		if (k==0){printf("%lld\n",(n+1)*n/2);continue;}

		memset(f,0x3f,sizeof(f)); f[0]=0;
		for (int i=0;i<n;i++){
			f[i+1]=min(f[i+1],f[i]+i+1);
			for (int j=1;j<=k+1;j++) if (a[i+j]=='1')
				f[min(n,i+j+k)]=min(f[min(n,i+j+k)],f[i]+i+j);
		}

		printf("%lld\n",f[n]);
	}
	return 0;
}