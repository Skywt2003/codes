#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55;

int a,b,c,d;
int n,m;
char ans[maxn][maxn];

int main(){
	a=read();b=read();c=read();d=read();
	n=m=50;
	for (int i=1;i<=25;i++)
	for (int j=1;j<=50;j++) ans[i][j]='A';
	a--;
	for (int i=26;i<=50;i++)
	for (int j=1;j<=50;j++) ans[i][j]='B';
	b--;

	for (int i=1;i<=24 && b>0;i+=2)
	for (int j=1;j<=50 && b>0;j+=2) ans[i][j]='B',b--;

	for (int i=27;i<=50 && (a>0||c>0||d>0);i+=2)
	for (int j=1;j<=50 && (a>0||c>0||d>0);j+=2){
		if (a>0) ans[i][j]='A',a--; else
		if (c>0) ans[i][j]='C',c--; else
		if (d>0) ans[i][j]='D',d--;
	}
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) putchar(ans[i][j]);
		printf("\n");
	}
	// if (a>0 || b>0 || c>0 || d>0) cout<<"ERROR!"<<endl;
	return 0;
}