#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int n,m,k,a[maxn];
int main(){
	while (scanf("%d",&n)!=-1){
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d%d",&m,&k);
		int isp=-1;
		if (m<a[1]) isp=1; else
		if (m>a[n]) isp=n; else
		for (int i=2;i<=n;i++) if (a[i-1]<m&&m<=a[i]) {isp=i;break;}
		for (int i=n+1;i>isp;i--) a[i]=a[i-1];
		a[isp]=m;
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("%d\n",a[n+1]);
		printf("%d\n",a[k+1]);
	}
	return 0;
}
