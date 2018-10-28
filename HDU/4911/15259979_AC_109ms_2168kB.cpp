#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,k,a[maxn],c[maxn];
long long cnt=0;
inline void msort(int L,int R){
	if (L>=R) return;
	int mid=((R-L)>>1)+L;
	msort(L,mid);msort(mid+1,R);
	int i=L,j=mid+1;
	for (int t=L;t<=R;t++){
		if (i<=mid&&(a[i]<=a[j]||j>R)) c[t]=a[i++]; else cnt+=(mid-i+1),c[t]=a[j++];
	}
	for (int i=L;i<=R;i++) a[i]=c[i];
}
long long llmax(long long x,long long y){return x<y?y:x;}
int main(){
	while (scanf("%d%d",&n,&k)!=-1){
		cnt=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		msort(1,n);
		printf("%lld\n",llmax(cnt-k,0));
	}
	return 0;
}