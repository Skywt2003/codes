#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=205;
bool vis[maxn][maxn];
int x[5],y[5],xx[5],yy[5];

signed main(){
	for (int i=0;i<4;i++) x[i]=read(),y[i]=read();
	for (int i=0;i<4;i++) xx[i]=read(),yy[i]=read();
	for (int i=min(x[0],x[2]);i<=max(x[0],x[2]);i++){
		for (int j=min(y[0],y[2]);j<=max(y[0],y[2]);j++){
			vis[i][j]=true;
		}
	}
	
}