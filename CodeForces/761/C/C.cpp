#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55;
int n,m;
int f[maxn][2][2][2];
char s[maxn];

signed main(){
	memset(f,0x3f,sizeof(f));
	f[0][0][0][0]=0;
	n=read();m=read();
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++){
			if (s[j]>='a' && s[j]<='z'){
				for (int ii=0;ii<2;ii++)
				for (int jj=0;jj<2;jj++)
					f[i][1][ii][jj]=min(f[i][1][ii][jj],min(f[i-1][0][ii][jj],f[i-1][1][ii][jj])+min(j-1,m-j+1));
			} else if (s[j]>='0' && s[j]<='9'){
				for (int ii=0;ii<2;ii++)
				for (int jj=0;jj<2;jj++)
					f[i][ii][1][jj]=min(f[i][ii][1][jj],min(f[i-1][ii][0][jj],f[i-1][ii][1][jj])+min(j-1,m-j+1));
			} else if (s[j]=='#' || s[j]=='*' || s[j]=='&'){
				for (int ii=0;ii<2;ii++)
				for (int jj=0;jj<2;jj++)
					f[i][ii][jj][1]=min(f[i][ii][jj][1],min(f[i-1][ii][jj][0],f[i-1][ii][jj][1])+min(j-1,m-j+1));
			}
		}
	}
	printf("%lld\n",f[n][1][1][1]);
	return 0;
}