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

const int maxn=105;

int n,k;
bool map[maxn][maxn];

signed main(){
	n=read();k=read();
	memset(map,0,sizeof(map));
	int x=1,y=1,cnt=0;
	while (cnt<k){
		map[x][y]=true;cnt++;
		y+=2;
		if (y>n){
			if (n&1) y%=n; else{
				if (y==n+1) y=2; else
				if (y==n+2) y=1;
			}
			x++;
		}
		if (x>n) break;
	}
	if (cnt<k) printf("NO\n"); else {
		printf("YES\n");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++) if (map[i][j]) putchar('L'); else putchar('S');
			printf("\n");
		}
	}
	return 0;
}