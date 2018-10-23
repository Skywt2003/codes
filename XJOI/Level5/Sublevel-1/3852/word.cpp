#include<cstdio>
#include<cstring>
#include<iostream>

#define int long long
using namespace std;
#define sqr(_) ((_)*(_))

int d1,d2,w1,w2;
bool ans=false;

inline int check(double d,double w,double h,bool islft){
	h-=0.5;
	if (islft) d-=1.0;
	double min_num=(h-d/2.0)*d;
	if (h<d) min_num=(1.0+h-0.5)*(h-0.5)/2.0;
	if (islft) min_num+=h+0.5;

	h+=1.0;
	double max_num=(h+d/2.0)*d;
	if (islft) max_num+=h-0.5;

	// if (h-0.5==58){
	// 	if (islft) printf("Left: %.2lf %.2lf\n",min_num,max_num); else
	// 	printf("Rght: %.2lf %.2lf\n",min_num,max_num);
	// }

	if (w<min_num) return -1; else
	if (min_num<=w&&w<=max_num) return 0; else
	if (w>max_num) return 1;
}

inline void solve(){
	int L=0,R=1e9+5;
	while (L<=R){
		int mid=((R-L)>>1)+L; // mid 枚举左
		int c1=check((double)d1,(double)w1,(double)mid,true);
		int c2=check((double)d2,(double)w2,(double)mid,false);
		if (c1==0&&c2==0) {ans=true;return;}
		if (c1+c2==0) {ans=false;return;}
		if (c1==-1||c2==-1) R=mid-1; else L=mid+1;
	}
}

signed main(){
	scanf("%lld%lld%lld%lld",&d1,&d2,&w1,&w2);
	solve();
	printf(ans?"Possible\n":"Impossible\n");
	return 0;
}