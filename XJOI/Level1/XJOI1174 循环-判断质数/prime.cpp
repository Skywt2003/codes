#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int t,n;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
bool check(int x){
	if (x==1) return false;
	for (int i=2;i<=x/2;i++) if (x%i==0) return false;
	return true;
}
int main(){
	t=read();
	for (int i=1;i<=t;i++){
		int x=read();
		if (check(x)) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}
