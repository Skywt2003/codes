#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
double f[maxn];
int T,n;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void Pretreatment(){
	for (int i=2;i<=1e5;i++){
		int cnt=0;f[i]=0.0;
		for (int j=1;j*j<=i;j++) if (i%j==0){
			if (i==j*j) cnt++,f[i]+=f[j]+1.0; else
			if (i%j==0) cnt+=2,f[i]+=f[i/j]+f[j]+2.0;
		}
		if (cnt-1) f[i]/=cnt-1;
	}
}
int main(){
	T=read();
	Pretreatment();
	int all_cnt=0;
	while (T--){
		printf("Case %d: ",++all_cnt);
		n=read();
		printf("%.6lf\n",f[n]);
	}
	return 0;
}
