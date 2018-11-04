#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long

using namespace std;

const int maxn=1e6+5;
const double eps=1.0e-6;
int n,x[maxn],y[maxn],ans[maxn];
int lst[maxn];
pair<double,double> lines[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

pair<double,double> get_line(int x1,int y1,int x2,int y2){
	double k=(double)(y2-y1)/(double)(x2-x1);
	double b=(double)y1-k*x1;
	return make_pair(k,b);
}

inline double get_y(pair<double,double> line,int x){
	return line.first*(double)x+line.second;
}

signed main(){
	freopen("beatall.in","r",stdin);
	freopen("beatall.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read(),ans[i]=-1,lst[i]=i-1;
	for (int i=1;i<=n;i++){
		if (ans[i]!=-1){
			lines[i]=get_line(x[ans[i]],y[ans[i]],x[i],y[i]);
			printf("%lld\n",ans[i]);
			continue;
		}
		int j=i-1;
		while (j>0 && get_y(lines[j],x[i])<=(double)y[i]) j=lst[j];
		if (j>0) lines[i]=get_line(x[i],y[i],x[j],y[j]),lst[i]=j,ans[i]=j; else lines[i]=make_pair(0.0,(double)y[i]),ans[i]=i;
		printf("%lld\n",ans[i]);
		if (i!=n && get_y(lines[i],x[i+1])>y[i+1]) ans[i+1]=i;
	}
	return 0;
}