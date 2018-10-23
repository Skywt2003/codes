#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=55;
int n;
int a[maxn],b[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read()-a[i];
	for (int i=1;i<=n;i++){
		if (b[i]<0){
			printf("Impossible\n");
			return 0;
		}
		for (int j=63;j>=0;j--){
			int now=(int)1<<j;
			if (((a[i]&now)==0) && (b[i]&now)){
				printf("Impossible\n");
				return 0;
			} else if (((a[i]&now)==0) && (b[i-1]&now)){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("Possible\n");
	return 0;
}