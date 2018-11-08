#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
// #define int long long
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl;

using namespace std;

const int maxn=55;
const double pi=3.14159265359;
int n,w1=0,w2=0;
vector<int> cmd1,cmd2;
bool f[400],g[400];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline char read_char(){
	char ch=getchar();
	while (ch!='l' && ch!='r' && ch!='f' && ch!='b') ch=getchar();
	return ch;
}

inline double calc_rui(double x,double y,double alpha){
	alpha=alpha/180.0*pi;
	return sqrt(sqr(x+y*cos(alpha)) + sqr(y*sin(alpha)));
}

inline double calc_dun(double x,double y,double alpha){
	alpha=180-alpha;
	alpha=alpha/180.0*pi;
	return sqrt(sqr(x-y*cos(alpha)) + sqr(y*sin(alpha)));
}

signed main(){
	n=read();
	cmd1.clear();cmd2.clear();
	for (int i=1;i<=n;i++){
		char ch=read_char();
		if (ch=='f') w1+=read(); else
		if (ch=='b') w2+=read(); else
		if (ch=='l') cmd1.push_back(read()); else
		if (ch=='r') cmd2.push_back(read());
	}

	f[0]=true;
	for (int i=0;i<(int)cmd1.size();i++){
		for (int j=0;j<360;j++) g[j]=f[j];
		for (int j=0;j<360;j++) if (!f[j]) f[j]|=g[(j-cmd1[i]+360)%360];
	}

	for (int i=0;i<(int)cmd2.size();i++){
		for (int j=0;j<360;j++) g[j]=f[j];
		for (int j=0;j<360;j++) if (!f[j]) f[j]|=g[(j+cmd2[i])%360];
	}

	// for (int i=0;i<=360;i++) cout<<i<<" : "<<f[i]<<endl;
	int now1=180,now2=180;
	int cnt=0;
	while ((!f[now1])&&(!f[now2])) now1--,now2++,cnt++;
	// write(cnt);
	if (cnt<=90) printf("%.15lf\n",calc_rui(w1,w2,cnt));
	else printf("%.15lf\n",calc_dun(w1,w2,cnt));
	return 0;
}