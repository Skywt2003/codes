#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=305;
const int M=1000000;
int n,m;
double bei;
double h[M+5];

signed main(){
	n=read();m=read()+1;
	bei=M/m;
	for (int i=1;i<=n;i++){
		int lx=0; double ans=0.0;
		for (int j=1;j<=m;j++){
			int x=read();
			if (j!=1){
				double slp=(double)x-(double)lx;
				double now=(double)lx;
				for (int k=(j-1)*bei+1;k<=j*bei;k++){
					now+=slp/bei;
					if (now>h[k]) ans+=(now-h[k]),h[k]=now;
				}
			}
			lx=x;
		}
		printf("%.12lf\n",ans/bei);
	}
	return 0;
}