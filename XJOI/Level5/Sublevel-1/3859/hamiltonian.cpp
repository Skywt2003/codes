#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=105;
int n;
char a[maxn][maxn];
int cnt[maxn];

inline char read_ch(){
	char ch=getchar();
	while (ch!='.'&&ch!='-'&&ch!='+') ch=getchar();
	return ch;
}

signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) a[i][j]=read_ch();
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) cnt[i]+=(a[i][j]=='+');
	}
	int lst=-1;
	for (int i=1;i<=n;i++){
		int max_num=-1,k=-1;
		for (int j=1;j<=n;j++) if ((lst==-1 || a[lst][j]=='+') && cnt[j]>max_num) max_num=cnt[j],k=j;
		printf("%lld ",k-1);
		cnt[k]=-1;
		for (int j=1;j<=n;j++) if (a[j][k]=='+') cnt[j]--;
		lst=k;
	}
	printf("\n");
	return 0;
}