#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=305;
int n,a[maxn],mx;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),mx=max(mx,a[i]);
	int now=1;
	if (a[now]>0) putchar('P'),a[now]--;
	while (true){
		int mx=0;
		if (now==1){
			mx=a[1];
			for (int i=2;i<=n;i++){
				putchar('R');
				if (a[i]>0) putchar('P'),a[i]--;
				mx=max(mx,a[i]);
			}
			now=n;
		} else if (now==n){
			mx=a[n];
			for (int i=n-1;i>=1;i--){
				putchar('L');
				if (a[i]>0) putchar('P'),a[i]--;
				mx=max(mx,a[i]);
			}
			now=1;
		}
		if (mx==0) break;
	}
	printf("\n");
	return 0;
}