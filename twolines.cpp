/*
 * XJOI CONTEST1002 T3 两条斜线
 * 180921 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl

const double eps=1e-7;
const int zero=1000;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;
int n,x[maxn],y[maxn],ans1=0,ans2=0;
int max_aans=0;
vector<int> vec1,vec2;
bool vis[maxn*2][maxn*2];

inline double Abs(double x){
	return x<0?-x:x;
}

inline double slope(int i,int j){
	return (double)((double)y[j]-(double)y[i])/((double)x[j]-(double)x[i]);
}

inline bool equ(double a,double b){
	return Abs(a-b)<eps;
}

int main(){
	n=read();
	for (int i=1;i<=n;i++) x[i]=read();
	for (int i=1;i<=n;i++) y[i]=read(),vis[x[i]+zero][y[i]+zero]=true;
	for (int i=1;i<=n;i++) {
		int cnt=1;
		for (int j=1;j<=n;j++) if (j!=i&&equ(slope(i,j),1.0)) cnt++;

		int b=y[i]-x[i];
		if (cnt>ans1){
			ans1=cnt;
			vec1.clear();
			vec1.push_back(b);
		} else if (cnt==ans1) vec1.push_back(b);
	
		cnt=1;
		for (int j=1;j<=n;j++) if (j!=i&&equ(slope(i,j),-1.0)) cnt++;

		b=y[i]+x[i];
		if (cnt>ans2){
			ans2=cnt;
			vec2.clear();
			vec2.push_back(b);
		} else if (cnt==ans2) vec2.push_back(b);
	}

	for (int i=0;i<vec1.size();i++)
	for (int j=0;j<vec2.size();j++)
		if (((vec2[j]-vec1[i])&1)||(!vis[(vec2[j]-vec1[i])/2+zero][(vec2[j]-vec1[i])/2+vec1[i]+zero])){
			printf("%d\n",ans1+ans2);
			return 0;
		}
	printf("%d\n",ans1+ans2-1);
	return 0;
}