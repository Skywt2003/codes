#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int T;
int n;

int strange_gcd(int x,int y){
	if (x==0 || y==0) return 0;
	if (x/y==1) return 1-strange_gcd(y,x%y);
	return 1;
}

signed main(){
	T=read();
	while (T--){
		int x=read(),y=read();
		if (x<y) swap(x,y);
		puts(strange_gcd(x,y)?"Stan wins":"Ollie wins");
	}
	return 0;
}