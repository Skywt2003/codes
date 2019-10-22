#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define pdd pair<double,double>
#define pii pair<int,int>

const int maxn=1000005;

int n,a,b,c;
int w[maxn],s[maxn];
int A[maxn],B[maxn];

pdd que[maxn];
int head=1,tail=1;

int f[maxn];

double slope(pdd aa,pdd bb){
	return (aa.second-bb.second)/(aa.first-bb.first);
}

signed main(){
	n=read();
	a=read(); b=read(); c=read();
	for (int i=1;i<=n;i++) w[i]=read(),s[i]=s[i-1]+w[i];
	for (int i=1;i<=n;i++) A[i]=2*a*s[i],B[i]=a*s[i]*s[i]+b*s[i]+c;

	head=tail=1;
	que[tail]=make_pair(0,0);
	for (int i=1;i<=n;i++){
		while (head<tail && slope(que[head],que[head+1]) > A[i]) head++;
		f[i]=que[head].second - A[i]*que[head].first + B[i];
		pdd now=make_pair(s[i], f[i]+a*s[i]*s[i]-b*s[i]);
		while (head<tail && slope(que[tail-1],que[tail]) < slope(que[tail-1],now)) tail--;
		que[++tail]=now;
	}
	printf("%lld\n",f[n]);
	return 0;
}