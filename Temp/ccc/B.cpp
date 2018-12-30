#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
#define int long long

const int maxn=100005;
int n,k;

struct WT{
	int x,y,id,ans;
}a[maxn];

priority_queue <int> heap[2];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool cmp(WT aa,WT bb){
	return aa.x<bb.x;
}

inline bool cmpid(WT aa,WT bb){
	return aa.id<bb.id;
}

signed main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].id=i;
	for (int i=1;i<=n;i++) a[i].y=read();
	sort(a+1,a+1+n,cmp);
	while (!heap[0].empty()) heap[0].pop();
	while (!heap[1].empty()) heap[1].pop();
	for (int i=1;i<=n;i++){
		a[i].ans=a[i].y;
		while (!heap[i+1&1].empty()) heap[i+1&1].pop();
		for (int j=1;j<=k && (!heap[i&1].empty());j++) a[i].ans+=heap[i&1].top(),heap[i+1&1].push(heap[i&1].top()),heap[i&1].pop();
		heap[i+1&1].push(a[i].y);
	}
	sort(a+1,a+1+n,cmpid);
	for (int i=1;i<=n;i++) cout<<a[i].ans<<" ";
	cout<<endl;
	return 0;
}