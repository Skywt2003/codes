#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<map>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int n,m;
int a[maxn];

namespace Subtask2{
	map<int,int> hsh;
	
	signed main(){
		hsh.clear();
		for (int i=1;i<=n;i++) hsh[a[i]]++;
		for (int i=1;i<=n;i++){
			int ops=read();
			if (ops==2){
				int x=read(),y=read(),k=read();
				printf("%lld\n",hsh[k]);
			}
		}
	}
}

signed main(){
	n=read();m=read();
	if (n>10000) return Subtask2::main();
	for (int i=1;i<=n;i++) a[i]=read();
	while (m--){
		int ops=read();
		if (ops==1){
			int L=read(),R=read();
			int tmp=a[R];
			for (int i=R;i>L;i--) a[i]=a[i-1];
			a[L]=tmp;
		} else {
			int L=read(),R=read(),k=read();
			int cnt=0;
			for (int i=L;i<=R;i++) cnt+=a[i]==k;
			printf("%lld\n",cnt);
		}
	}
	return 0;
}