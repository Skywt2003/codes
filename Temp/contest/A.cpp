#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	int k=read(),a=read(),b=read(),v=read();
	int num=0,ans=0;
	while (a>0){
		num=1;
		while (b>0 && num<k) if (num<k) num++,b--;
		a-=num*v;ans++;
	}
	printf("%lld\n",ans);
	return 0;
}