#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int tot,a,b,c;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	int x=read();
	while (x-(-1)){
		tot++;
		if (x==1) a++; else
		if (x==2) b++; else
		if (x==3) c++; else tot--;
		x=read();
	}
	printf("A=%d\nB=%d\nC=%d\nTot=%d\n",a,b,c,tot);
	if (a>tot/2) printf("A-yes\n"); else
	if (b>tot/2) printf("B-yes\n"); else
	if (c>tot/2) printf("C-yes\n"); else
	printf("all-NO\n");
	return 0;
}
