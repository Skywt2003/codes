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

signed main(){
	n=read(); k=read();
	for (int i=0;i<31;i++){
		int now=n-k*i;
		if (now<=0) continue;
		int s1=0,s2=0;
		for (int j=0;j<31;j++) if (now&(1<<j)) s1++,s2+=1<<j;
		if (s1<=i && i<=s2){
			printf("%lld\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}