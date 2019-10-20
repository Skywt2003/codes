// This solution is wrong.

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

int n,p,t[maxn],ans[maxn];

struct node{
	int x,y;

	bool operator <(node bb)const{
		return y > bb.y;
	}
	bool operator >(node bb)const{
		return y < bb.y;
	}
};

node b[maxn];

priority_queue<node> heap;

bool compare_s(node aa,node bb){
	return (aa.x<bb.x)||(aa.x==bb.x && aa.y<bb.y);
}

signed main(){
	n=read(); p=read();
	for (int i=1;i<=n;i++){
		t[i]=read();
		b[i]=(node){t[i],i};
	}

	sort(b+1,b+1+n,compare_s);
	while (!heap.empty()) heap.pop();

	int nowt=0,pt=0;
	for (;pt<=n;){
		while (pt+1<=n && nowt>=b[pt+1].x) heap.push(b[++pt]);
		if (heap.empty()){
			pt++; nowt=b[pt].x,heap.push(b[pt]);
			while (pt+1<=n && nowt>=b[pt+1].x) heap.push(b[++pt]);
		}
		node now=heap.top(); heap.pop();
		nowt+=p; ans[now.y]=nowt;
		if (pt==n && heap.empty()) break;
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}