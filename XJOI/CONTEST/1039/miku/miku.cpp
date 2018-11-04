#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define int long long

using namespace std;

const int maxn=1505;
int n,m,a[maxn],L,R;

set<int> s;
set<int>::iterator it;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void make_answer(int x,int y){
	it=s.lower_bound(x);
	for (;(it!=s.end()) && (*it<y);){
		swap(a[*it],a[*it+1]);
		if ((*it-1>=1) && a[*it  ]<a[*it-1]) s.insert(*it-1);
		if ((*it+2<=n) && a[*it+2]<a[*it+1]) s.insert(*it+1);
		s.erase(it);it=s.lower_bound(x);
	}
}

signed main(){
	n=read();m=read();L=read();R=read();
	for (int i=1;i<=n;i++) a[i]=read();
	s.clear();
	for (int i=2;i<=n;i++) if (a[i]<a[i-1]) s.insert(i-1);
	while (m--){
		int x=read(),y=read();
		make_answer(x,y);
	}
	for (int i=L;i<=R;i++) printf("%lld ",a[i]);
	printf("\n");
	return 0;
}