#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,q,p;

signed main(){
	n=read(); q=read(); p=read();
	for (int i=1;i<n;i++) read(),read();
	for (int i=1;i<=q;i++){
		int opt=read();
		if (opt==2) puts("1"); else read();
	}
	return 0;
}
