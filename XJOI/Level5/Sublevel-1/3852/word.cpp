#include<cstdio>
#include<cstring>
#include<iostream>

#define int long long
using namespace std;

int d1,d2,w1,w2;
bool ans=false;

inline void solve(){
	int L=1,R=1e9;
	while (L<=R){
		int mid=((R-L)>>1)+L;
		int minx=
	}
}

signed main(){
	scanf("%lld%lld%lld%lld",&d1,&d2,&w1,&w2);
	solve();
	printf(ans?"Possible":"Impossible");
	return 0;
}