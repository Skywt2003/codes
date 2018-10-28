#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=4005;
int n,cnt=0;
double a[maxn],sum=0.0,ans=1.0e8;

inline double Abs(double x){return x<0?-x:x;}

inline bool same(double a,double b){
	return Abs(a-b)<1e-8;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++){
		scanf("%lf",&a[i]);
		double delta=(a[i])-(double)((int)a[i]);
		if (same(delta,0.0)) cnt++;
		sum+=delta;
	}
	for (int i=0;i<=cnt;i++){
		ans=min(ans,Abs(sum-(double)(n-i)));
	}
	printf("%.3lf\n",ans);
	return 0;
}