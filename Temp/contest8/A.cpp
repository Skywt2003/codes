#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int x,y,z;

signed main(){
	x=read();y=read();z=read();
	int now=1;
	while (now<x){
		if (y/now<z){
			printf("-1\n");
			return 0;
		}
		now=now*z;
	}
	int cnt=0;
	while (now<=y){
		printf("%lld ",now);
		cnt++;
		if (y/now<z) break;
		now=now*z;
	}
	if (cnt==0) cout<<-1<<endl;
	return 0;
}