#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=55;
int n;
int a[maxn],b[maxn];
bool f[maxn][maxn][2];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int na(){
	printf("Impossible\n");
	return 0;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read()-a[i];
	memset(f,true,sizeof(f));
	for (int i=1;i<=n;i++){
		for (int j=63;j>=0;j--){
			int now=(int)1<<j;
			if ((a[i]&now)==0 && (b[i]&now)   ) return na();
			if ((a[i]&now)==0 && (b[i]&now)==0) f[i+1][j][1]=f[i][j][1]=false,f[i+1][j][0]=f[i][j][0];
			if ((a[i]&now)    && (b[i]&now)==0) f[i+1][j][0]=f[i][j][1],f[i+1][j][1]=f[i][j][0];
			if ((a[i]&now)    && (b[i]&now))    f[i+1][j][0]=f[i][j][0]=false,f[i+1][j][1]=f[i][j][1];
			if (f[i][j][0]==false&&f[i][j][1]==false) return na();
		}
	}
	printf("Possible\n");
	return 0;
}