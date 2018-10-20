#include<cstdio>
#include<cstring>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=1005;
int n,a[maxn],b[maxn],c[maxn];

struct WT{
	int a,id;
	bool chs;
}f[maxn];

inline int read(){
	int ret=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret;
}

inline bool cmp(WT x,WT y){
	return x.a<y.a;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++){
		f[i].a=min(a[i],b[i]);
		f[i].id=i;
		if (a[i]<b[i]) f[i].chs=0; else f[i].chs=1;
	}
	sort(f+1,f+1+n,cmp);
	int L=0,R=n+1;
	for (int i=1;i<=n;i++) if (f[i].chs==0) c[++L]=f[i].id; else c[--R]=f[i].id;
	int tme=0,sum=0;
	for (int i=1;i<=n;i++){
		sum+=a[c[i]];
		if (tme<sum) tme=sum+b[c[i]]; else tme+=b[c[i]];
	}
	printf("%lld\n",tme);
    for (int i=1;i<=n;i++) printf("%lld ",c[i]);
	printf("\n");
	return 0;
}