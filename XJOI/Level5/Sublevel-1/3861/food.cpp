#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

#define int long long
using namespace std;

const int maxn=55,INF=1e10;
int n,m,money;
int c[maxn][maxn];
int ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int read_ch(){
	char ch=getchar();
	while ((ch<'0'||ch>'9')&&(ch<'a'||ch>'z')&&(ch<'A'||ch>'Z')) ch=getchar();
	return ch;
}

inline int get_num(char ch){
	if (ch>='0'&&ch<='9') return ch-'0'; else
	if (ch>='A'&&ch<='Z') return ch-'A'+10; else
	if (ch>='a'&&ch<='z') return ch-'a'+36;
}

inline bool check(int x){
	int total=0;
	for (int i=1;i<=7;i++){
		int now=INF;
		for (int k=1;k<=m;k++){
			int sum=0;
			for (int j=i;j<=x;j+=7) sum+=c[j][k];
			now=min(now,sum);
		}
		total+=now;
	}
	return total<=money;
}

signed main(){
	n=read();m=read();money=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			c[i][j]=get_num(read_ch());
	int L=0,R=n;
	while (L<=R){
		int mid=((R-L)>>1)+L;
		if (check(mid)) ans=mid,L=mid+1; else R=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}