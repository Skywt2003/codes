#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;
const int maxs=(1<<20)+5;

int T;
int n;
int sg[maxs],nxt[25];
bool flg[25];

void prebuild(){
	memset(sg,-1,sizeof(sg));
	for (int i=0;i<(1<<20);i++) if (sg[i]==-1){
		memset(flg,0,sizeof(flg));
		int last_blank=-1;
		for (int j=0;j<20;j++) if (i&(1<<j)) nxt[j]=last_blank; else nxt[j]=last_blank=j;
		for (int j=19;j>=0;j--) if (i&(1<<j)){
			if (nxt[j]==-1) break;
			int hou=i-(1<<j)+(1<<nxt[j]);
			flg[sg[hou]]=true;
		}
		for (int j=0;j<=20;j++) if (!flg[j]) {sg[i]=j;break;}
	}
}

signed main(){
	prebuild();

	T=read();
	while (T--){
		n=read();
		int ans=0;
		for (int i=1;i<=n;i++){
			int now=0,m=read();
			for (int j=1;j<=m;j++) now|=1<<(20-read());
			ans^=sg[now];
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}