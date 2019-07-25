#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int T,n,a[maxn];
bool win[maxn];

signed main(){
	T=read();
	while (T--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		memset(win,0,sizeof(win)); win[1]=true;
		for (int i=2;i<=n;i++){
			if (win[i-1] && (a[i]&1)) win[i]=true;
			if (win[i-1]==false) win[i]=true;
		}
		printf(win[n]?"yes\n":"no\n");
	}
	return 0;
}