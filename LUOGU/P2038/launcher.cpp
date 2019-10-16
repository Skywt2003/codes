#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=130;

int n,d;
int sum[maxn][maxn];
int ans=-1,cnt=0;

signed main(){
	d=read();
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		sum[x][y]=read();
	}

	for (int i=0;i<=128;i++)
		for (int j=0;j<=128;j++){
			int now=0;
			for (int k=max(0,i-d);k<=min(128,i+d);k++)
				for (int t=max(0,j-d);t<=min(128,j+d);t++)
					now+=sum[k][t];
			if (now>ans) ans=now,cnt=1; else
			if (now==ans) cnt++;
		}
	printf("%d %d\n",cnt,ans);
	return 0;
}