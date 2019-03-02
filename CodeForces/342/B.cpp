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

const int maxn=1e5+5;

int n,m,s,t;
struct wt{
	int t,l,r;
}a[maxn];

signed main(){
	n=read();m=read();s=read();t=read();
	for (int i=1;i<=m;i++) a[i].t=read(),a[i].l=read(),a[i].r=read();
	for (int i=1;i<=m;i++){
		if (s==t) return 0;
		for (int k=1;k<=a[i].t-a[i-1].t-1;k++){
			if (s<t) putchar('R'),s++; else putchar('L'),s--;
			if (s==t) return 0;
		}
		if (a[i].l<=s && s<=a[i].r) putchar('X'); else
		if (s<t){
			if (a[i].l<=s+1 && s+1<=a[i].r) putchar('X'); else putchar('R'),s++;
		} else {
			if (a[i].l<=s-1 && s-1<=a[i].r) putchar('X'); else putchar('L'),s--;
		}
		if (s==t) return 0;
	}
	while (s<t) putchar('R'),s++;
	while (s>t) putchar('L'),s--;
	return 0;
}