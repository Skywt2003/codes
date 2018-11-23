#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
#define int long long

const int maxn=35;

int n,sum=0,a[maxn],ans[maxn],now[maxn];
int ans_num=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	for (int i=1;i<=n;i++){
		int ji=sum/i;
		if (ji==0) break;
		memset(now,0,sizeof(now));
		for (int j=1;j<=i;j++) now[j]=ji;
		for (int j=1;j<=sum%i;j++) now[j]++;
		int now_num=0;
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++) if (now[k]>a[j]) now_num++;
		}
		if (now_num>ans_num){
			for (int j=1;j<=n;j++) ans[j]=now[j];
			ans_num=now_num;
		}
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
} 