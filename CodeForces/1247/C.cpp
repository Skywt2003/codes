#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}


int n,k;

int popcount(int x){
	int ret=0;
	while (x) ret+=x&1,x>>=1;
	return ret;
}

signed main(){
	n=read(); k=read();
	for (int i=0;i<31;i++){
		int now=n-k*i;
		if (now<=0) continue;
		if (popcount(now) <= i){
			printf("%lld\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}