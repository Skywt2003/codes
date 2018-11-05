#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long

using namespace std;

const int maxn=1e5+5;

int tt;
int n,m;
int a[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();m=read();tt=read();
	for (int i=1;i<=n;i++) a[i]=read();

	for (int i=1;i<=m;i++){
		int opt=read();
		if (opt==1){
			int x=read(),y=read(),k=read();
			for (int j=x;j<=y;j++) a[j]=a[j]*k%tt;
		} else if (opt==2){
			int x=read(),y=read(),k=read();
			for (int j=x;j<=y;j++) a[j]=(a[j]+k)%tt;
		} else if (opt==3){
			int x=read(),y=read();
			int ret=0;
			for (int j=x;j<=y;j++) ret=(ret+a[j])%tt;
			printf("%lld\n",ret);
		}
	}

	return 0;
}