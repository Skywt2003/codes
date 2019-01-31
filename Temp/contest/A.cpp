#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55;

int n,m;
bool vis[maxn][maxn];

signed main(){
	n=read();m=read();
	int nowx=1,nowy=1,rght=1;
	while (nowx<=n){
		vis[nowx][nowy]=true;
		nowy+=rght;
		if (nowy>m || nowy<1){
			nowy-=rght;
			vis[nowx+1][nowy]=true;
			rght=-rght;
			nowx+=2;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) if (vis[i][j]) putchar('#'); else putchar('.');
		printf("\n");
	}
	return 0;
}