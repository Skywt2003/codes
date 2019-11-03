#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int T,n;

int sg(int x,int y){
	int num=x|y;
	for (int i=0;i<31;i++) if (!(num&(1<<i))) return i;
	return 31;
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif
	T=read();
	while (T--){
		n=read(); int ans=0;
		for (int i=1;i<=n/2;i++){
			int x=read(),y=read();
			ans^=sg(x-1,y-1);
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}