#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1000005;

int n;
long long d[maxn],c[maxn],p[maxn];
long long f[maxn],sump[maxn],summ[maxn];
long long a[maxn],b[maxn];
int head=0,tail=0,que[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline double X(int i){return (double)sump[i];}
inline double Y(int i){return (double)b[i];}

inline double slope(int i,int j){
	return (double)(Y(i)-Y(j))/(X(i)-X(j));
}

int main(){
	n=read();
	for (int i=1;i<=n;i++){
		d[i]=read();p[i]=read();c[i]=read();
		sump[i]=sump[i-1]+p[i];
		summ[i]=summ[i-1]+p[i]*d[i];
	}
	for (int i=1;i<=n;i++) a[i]=c[i]+d[i]*sump[i]-summ[i],f[i]=c[i]+d[i]*sump[i]-summ[i];
	head=tail=1;
	for (int i=1;i<=n;i++){
		while ((head<tail)&&(slope(que[head],que[head+1])<d[i])) head++;
		f[i]=min(f[i],a[i]+b[que[head]]-d[i]*sump[que[head]]);
		b[i]=summ[i]+f[i];
		while ((head<tail)&&(slope(que[tail-1],que[tail])>slope(que[tail-1],i))) tail--;
		que[++tail]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}