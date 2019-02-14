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

const int maxn=105;
int n;
int a[maxn];

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	n=read();int sum=0;
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	sort(a+1,a+1+n,cmp);
	int now=0;
	for (int i=1;i<=n;i++){
		now+=a[i];
		if (now>sum-now){
			printf("%lld\n",i);
			return 0;
		}
	}
	printf("%lld\n",n);
	return 0;
}