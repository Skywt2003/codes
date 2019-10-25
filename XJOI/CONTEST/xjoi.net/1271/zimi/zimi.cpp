#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;

signed main(){
	n=read();
	if (n==1) puts("1 2 3 4 5 6 7 8 9\n"); else
	if (n==2) puts("-1\n"); else
	if (n==3) puts("153 370 371 407\n"); else
	if (n==4) puts("1634 8208 9474\n"); else
	if (n==5) puts("54748 92727 93084\n"); else
	if (n==6) puts("548834\n"); else
	if (n==7) puts("1741725 4210818 9800817 9926315\n"); else
	if (n==8) puts("24678050 24678051 88593477\n"); else
	if (n==9) puts("146511208 472335975 534494836 912985153\n"); else 
	if (n==10) puts("4679307774\n"); else 
	puts("-1\n");

	return 0;
}