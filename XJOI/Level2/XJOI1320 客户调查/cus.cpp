#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10005;
int n,f[2][maxn];
struct CusData{
	int s,t;
}a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool cmp(CusData aa,CusData bb){
	return aa.t<bb.t;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i].s=read(),a[i].t=read();
	sort(a+1,a+1+n,cmp);
	memset(f,63,sizeof(f));int INF=f[0][0];
	f[0][0]=f[1][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++){
			if (f[1-(i&1)][j]<=a[i].s&&a[i].t<f[i&1][j+1]) f[i&1][j+1]=a[i].t;
			if (f[1-(i&1)][j]<f[i&1][j]) f[i&1][j]=f[1-(i&1)][j];
		}
	}
	int t=n;
	while (t>0&&f[n&1][t]==INF) t--;
	printf("%d\n",t);
	return 0;
}
