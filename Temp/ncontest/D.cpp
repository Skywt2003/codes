#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e4+5;
const int tt=1e9+7;

int n;
char a[5][maxn];
int f[maxn][10];

bool can_put(int x,int y){
	if (a[x][y]=='X' || a[x][y]=='O') return false;
	return true;
}

void plus_mod(int &x,int y){
	x=x+y;
	if (x>tt) x-=tt;
}

signed main(){
	n=read();
	char ch=getchar();while (ch!='.'&&ch!='X'&&ch!='O') ch=getchar();
	for (int i=0;i<3;i++){
		for (int j=0;j<n;j++){
			a[i][j]=ch;
			if (i==2 && j==n-1) break;
			ch=getchar();while (ch!='.'&&ch!='X'&&ch!='O') ch=getchar();
		}
	}
	f[0][0]=1;
	for (int i=0;i<n;i++){
		f[i][0]=f[i-1][(1<<3)-1];
		for (int j=0;j<(1<<3);j++){
			for (int t=0;t<3;t++) if (can_put(i-1,t)&&can_put(i,t) && ((j&(1<<t))==0)) plus_mod(f[i][j],f[i-1][(1<<3)-1-(1<<t)]);
			for (int t=0;t<2;t++) if (can_put(i,t)&&can_put(i,t+1) && j&(1<<t)==0 && j&(1<<(t+1))==0) plus_mod(f[i][j+(1<<t)+(1<<t+1)],f[i][j]);
		}
	}
}