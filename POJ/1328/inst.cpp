#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1005;
int n,d,x[maxn],y[maxn];
struct LineData{
	double s,t;
}a[maxn];
inline bool cmp(LineData aa,LineData bb){
	return aa.s<bb.s;
}
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline double min(double x,double y){
	if (x>y) return y; else return x;
}
int main(){
	freopen("inst.in","r",stdin);
	freopen("inst.out","w",stdout);
	int id=0;
	n=read();d=read();
	while (n||d){
		id++;bool can=true;
		for (int i=1;i<=n;i++){
			x[i]=read(),y[i]=read();
			if (y[i]>d) can=false;
//			a[i].s=(double)x[i]-(double)sqrt((double)d)/(double)y[i];
//			a[i].t=(double)sqrt((double)d)/(double)y[i]+(double)x[i];
			a[i].s=(double)x[i]-(double)sqrt((double)(d*d-y[i]*y[i]));
			a[i].t=(double)x[i]+(double)sqrt((double)(d*d-y[i]*y[i]));
			if (a[i].s>a[i].t) swap(a[i].s,a[i].t);
		}
		if (!can){
			printf("Case %d: -1\n",id);
			n=read();d=read();
			continue;
		}
		sort(a+1,a+1+n,cmp);
//		for (int i=1;i<=n;i++) printf("%6f,%6f\n",a[i].s,a[i].t); 
		int tot=0;
		for (int i=1;i<=n;){
			int j;
			double tail=a[i].t;
			for (j=i;(j+1<=n)&&(a[j+1].s<=tail);tail=min(tail,a[++j].t));
			tot++;i=j+1;
		}
		printf("Case %d: %d\n",id,tot);
		n=read();d=read();
	}
	return 0;
}
