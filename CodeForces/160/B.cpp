#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=205,INF=1e9;
int n;
char a[maxn];

signed main(){
	n=read();
	scanf("%s",a+1);
	sort(a+1,a+1+n);
	sort(a+n+1,a+1+2*n);
	// printf("%s\n",a+1);
	int flg=true;
	for (int i=1;i<=n;i++){
		if (a[i]<=a[i+n]) {flg=false;break;}
	}
	if (flg) {printf("YES\n");return 0;}
	flg=true;
	for (int i=1;i<=n;i++){
		if (a[i]>=a[i+n]) {flg=false;break;}
	}
	if (flg) {printf("YES\n");return 0;}
	printf("NO\n");
	return 0;
}