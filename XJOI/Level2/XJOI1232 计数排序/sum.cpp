#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10000005,maxx=1000005,tt=1000000;
int n,a[3],hsh[maxx];
long long sum=0;
int main(){
	scanf("%d",&n);
	a[0]=1;a[1]=2;hsh[1]=hsh[2]=1;
	for (int i=2;i<n;i++){
		a[i%3]=(a[(i+1)%3]+a[(i+2)%3])%tt;
		hsh[a[i%3]]++;
	}
	int j=-1;
	for (int i=0;i<tt;i++) if (hsh[i]){
		for (int k=0;k<hsh[i];k++){
			j++;
			sum=sum+(long long)((long long)i*(long long)j)%tt;
			if (sum>=tt) sum-=tt;
		}
	}
	printf("%lld\n",sum);
	return 0;
}
