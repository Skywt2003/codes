#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n;
struct TaskData{
	int x,y;
}a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int tme(TaskData aa,TaskData bb){
	return max(aa.x+aa.y,aa.x+bb.x+bb.y);
}
inline bool cmp(TaskData aa,TaskData bb){
	return (tme(aa,bb)<tme(bb,aa));
}
int main(){
	freopen("war.in","r",stdin);
	freopen("war.out","w",stdout);
	n=read();int t=0;
	while (n!=0){
		t++;
		for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
		sort(a+1,a+1+n,cmp);
		int lstx=0,lsty=0;
		for (int i=1;i<=n;i++){
			lstx+=a[i].x;
			lsty=max(lstx+a[i].y,lsty);
		}
		printf("Case %d: %d\n",t,max(lstx,lsty));
		n=read();
	}
	return 0;
}
