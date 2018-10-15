#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int x,y;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int myabs(int x){
	if (x<0) return -x; else return x;
}
int main(){
	bool flg=1;
	for (int i=1;i<=5;i++) if (flg)
	for (int j=1;j<=5;j++) if (flg){
		int xx=read();
		if (xx==1) {x=i,y=j;flg=0;break;}
	}
	printf("%d\n",myabs(x-3)+myabs(y-3));
	return 0;
}
