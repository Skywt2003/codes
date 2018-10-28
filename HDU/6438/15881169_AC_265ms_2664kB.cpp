#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=200005;

int T,n,a[maxn];
long long ans_num=0,ans;

struct Goods{
	int x;
	bool sld;
	bool operator <(const Goods b) const {
		return (x>b.x)||((x==b.x)&&(!sld));
	}
};
priority_queue <Goods> heap;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	T=read();
	while (T--){
		n=read();ans=ans_num=0;
		while (!heap.empty()) heap.pop();
		for (int i=1;i<=n;i++){
			a[i]=read();
			if ((heap.empty())||(heap.top().x>=a[i])) heap.push((Goods){a[i],false}); else {
				Goods now=heap.top();heap.pop();
				if (now.sld==false) ans_num+=2; else heap.push((Goods){now.x,false});
				ans+=(long long)a[i]-now.x;
				now.x=a[i];now.sld=true;
				heap.push(now);
			}
		}
		printf("%lld %lld\n",ans,ans_num);
	}
	return 0;
}