#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int flg[5][5]={{ 0,-1, 1, 1,-1},
					 { 1, 0,-1, 1,-1},
					 {-1, 1, 0,-1, 1},
					 {-1,-1, 1, 0, 1},
					 { 1, 1,-1,-1, 0}};
const int maxn=205;
int n,x,y,a[maxn],b[maxn],ans1,ans2;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();x=read();y=read();
	for (int i=0;i<x;i++) a[i]=read();
	for (int i=0;i<y;i++) b[i]=read();
	for (int i=0;i<n;i++){
		int f=flg[a[i%x]][b[i%y]];
		if (f==1) ans1++; else
		if (f==-1) ans2++; 
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
