#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=155,maxnum=10;
int n,a[maxn],num=0;
bool f[maxn][maxn][maxnum];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),f[i][i][a[i]]=true,num=max(num,a[i]);
	for (int L=1;L<n;L++){
		for (int i=1;i<=n-L+1;i++){
			int j=i+L;
			for (int k=i+1;k<=j;k++){
				for (int x=0;x<=num;x++)
				for (int y=0;y<=num;y++)
					f[i][j][x+y>>1]|=f[i][k-1][x]&&f[k][j][y];
			}
		}
	}
	for (int i=0;i<=num;i++) if (f[1][n][i]) printf("%lld ",i);
	printf("\n");
	return 0;
}