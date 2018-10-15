#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=70005;
int n,nn,num[maxn];
bool prime[maxn];
inline void make_prime(){
	memset(prime,1,sizeof(prime));
	for (int i=2;i<=sqrt(n)+2;i++)
	for (int j=2;j<=(sqrt(n)+2)/i;j++)
		if (i*j<70000) prime[i*j]=false;
}
int main(){
	scanf("%d",&n);nn=n;
	make_prime();
	for (int i=sqrt(n)+1;i>=2&&nn>1;i--) if ((prime[i])&&(n%i==0)) while (nn%i==0) num[i]++,nn/=i;
	int now=0;
	for (int i=2;i<=sqrt(n)+1;i++) if (num[i]){
		now++;
		if (now!=1) printf("*");
		if (num[i]==1) printf("%d",i); else printf("%d^%d",i,num[i]);
	}
	if (nn!=1){
		if (now==0) printf("%d\n",nn); else printf("*%d\n",nn);
	}
	printf("\n");
	return 0;
}
