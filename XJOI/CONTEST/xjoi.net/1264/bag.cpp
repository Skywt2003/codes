#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=504;

int n,L,sn;
int c[maxn],v[maxn];
int s[maxn];

bool f[maxn][maxn][maxn];

// int w[maxn][15];
set<int> ans;

// void binary_deliver(){
// 	for (int i=1;i<=n;i++)
// 		for (int j=10;j>=0;j--)
// 			if (c[i]>=(1<<j)) c[i]-=1<<j,w[i][++w[i][0]]=v[i]*(1<<j);
// }

signed main(){
	n=read(); L=read();
	for (int i=1;i<=n;i++) c[i]=read(),v[i]=read();
	sn=read();
	for (int i=1;i<=sn;i++) s[i]=read();

	// binary_deliver();

	f[0][0][0]=true;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=i;j++){
			for (int t=0;t<=L;t++)
				f[i][j][t]|=f[i-1][j][t];
			if (j==0) continue;
			for (int k=1;k<=c[i];k++)
				for (int t=L;t>=k*v[i];t--)
					f[i][j][t]|=f[i-1][j-1][t-k*v[i]];
		}

	ans.clear();
	for (int i=1;i<=sn;i++)
		for (int j=1;j<=L;j++)
			if (f[n][s[i]][j]) ans.insert(j);

	for (set<int>::iterator i=ans.begin();i!=ans.end();i++) printf("%d ",*i);
	printf("\n");
	return 0;
}