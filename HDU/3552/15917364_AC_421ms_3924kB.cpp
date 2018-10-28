#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100005,INF=1<<30;
int T,n,a[maxn],b[maxn];
int maxa,maxb,ans;
struct Element{
	int a,id;
	bool operator <(Element bb)const{
		return a<bb.a;
	}
};
priority_queue <Element> heap;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	T=read();
	int cas=0;
	while (T--){
		while (!heap.empty()) heap.pop();
		n=read();
		maxa=maxb=0;ans=INF;
		for (int i=1;i<=n;i++){
			a[i]=read(),b[i]=read();
			heap.push((Element){a[i],i});
		}
		ans=heap.top().a;
		for (int i=1;i<=n;i++){
			maxb=max(maxb,b[heap.top().id]);
			heap.pop();
			maxa=heap.top().a;
			ans=min(ans,maxa+maxb);
		}
		printf("Case %d: %d\n",++cas,ans);
	}
	return 0;
}