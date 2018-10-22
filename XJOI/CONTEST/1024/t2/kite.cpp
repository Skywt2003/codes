#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=4e5+5,INF=1e18;
int n,m;
int a[maxn];
int stack[maxn],stack_top=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int find(int x){
	int L=1,R=stack_top;
	while (L<=R){
		int mid=((R-L)>>1)+L;
		if (a[mid]>x && a[mid-1]<=x) return mid; else
		if (a[mid]>x) R=mid-1; else L=mid+1;
	}
	// printf("ERROR: Find %lld faild\n",x);
	// printf("STACK: ");for (int i=1;i<=stack_top;i++) printf("%lld ",stack[i]);printf("\n");
	return -1;
}

inline int solve(){
	memset(stack,0,sizeof(stack));
	stack[0]=-INF;stack_top=0;
	for (int i=1;i<=n;i++){
		if (stack_top==0 || a[i]>stack[stack_top]) stack[++stack_top]=a[i]; else {
			int f=find(a[i]);
			if (f!=-1) stack[f]=a[i];
		}
	}
	return stack_top;
}

namespace Subtask2{
	signed main(){
		if (n==0) return printf("0\n"),0;
		for (int i=1;i<=n;i++) a[i]=read();
		bool up=a[1]<a[2];
		for (int i=1;i<=m;i++){
			int x=read(),y=read();
			if (up) printf("%lld\n",a[x]==y?n:n-1); else {
				if (x==1 && y>a[x]) printf("1\n"); else
				if (x==n && y<a[x]) printf("1\n"); else
				printf("2\n");
			}
		}
		return 0;
	}
}

signed main(){
	n=read();m=read();
	if (n>1000 || m>1000) return Subtask2::main();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		swap(a[x],y);
		printf("%lld\n",solve());
		swap(a[x],y);
	}
	return 0;
}