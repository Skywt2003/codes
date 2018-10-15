#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10005;
int n,midnum_x,midnum_y,tmp[maxn],ans=0;
struct WT{
	int x,y;
}a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool cmp_by_y(WT aa,WT bb){
	return aa.y<bb.y;
}
inline bool cmp(WT aa,WT bb){
	return ((aa.x<bb.x)||((aa.x==bb.x)&&(aa.y<bb.y)));
}
inline int abs_(int x){
	if (x<0) return -x; else return x;
}
inline int getdst(int x_1,int y_1,int x_2,int y_2){
	return abs_(x_1-x_2)+abs_(y_1-y_2);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	sort(a+1,a+1+n,cmp_by_y);
	midnum_y=a[(n+1)>>1].y;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++) tmp[i]=a[i].x-i+1;
	sort(tmp+1,tmp+1+n);
	midnum_x=tmp[(n+1)>>1];
	for (int i=1;i<=n;i++) ans+=getdst(a[i].x,a[i].y,midnum_x+i-1,midnum_y);
	printf("%d\n",ans);
	return 0;
}
