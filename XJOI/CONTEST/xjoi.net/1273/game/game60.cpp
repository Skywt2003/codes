#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,m;

bool ans[10][10];

void prebuild(){
	ans[1][1]=1;
	for (int i=2;i<=6;i++) ans[1][i]=ans[i][1]=false;
	ans[2][2]=false; ans[2][3]=ans[3][2]=false; ans[2][4]=ans[4][2]=true; ans[2][5]=ans[5][2]=true;
	ans[3][3]=false; ans[3][4]=ans[4][3]=true;  ans[3][5]=ans[5][3]=true;
	ans[4][4]=true; ans[4][5]=ans[5][4]=true;
	ans[5][5]=true;
}

signed main(){
	prebuild();
	while (~scanf("%lld%lld",&n,&m)) printf(ans[n][m]?"WIN\n":"LOSE\n");
}