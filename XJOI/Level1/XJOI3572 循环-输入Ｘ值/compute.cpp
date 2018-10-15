#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
double x,now,ans=0.0;
double _abs(double x){
	if (x<0) return -x; else return x;
}
int main(){
	scanf("%lf",&x);
	int cnt=1;now=x;
	while (1){
		ans+=now/(double)cnt;
		if (_abs(now/(double)cnt)<1e-5) break;
		cnt++;
		now=now*x;
	}
	printf("%.6f\n",ans);
	return 0;
}
