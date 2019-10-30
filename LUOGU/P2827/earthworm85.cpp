#include<bits/stdc++.h>

using namespace std;

// #define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

priority_queue<int> heap;
int n,m,q,u,v,t;

signed main(){
	n=read(); m=read(); q=read(); u=read(); v=read(); t=read();
	for (int i=1;i<=n;i++) heap.push(read());

	for (int i=1;i<=m;i++){
		int now=heap.top()+(i-1)*q; heap.pop();
		if (i%t==0) printf("%d ",now);
		int now1=(long long)now*u/v,now2=now-now1;
		heap.push(now1-i*q); heap.push(now2-i*q);
	}
	printf("\n");

	for (int i=1;i<=n+m;i++){
		int now=heap.top()+m*q; heap.pop();
		if (i%t==0) printf("%d ",now);
	}
	printf("\n");
	return 0;
}