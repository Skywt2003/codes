#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int maxx=1000005;
int t,sum[maxx],primes[maxx];
bool vis[maxx];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
//inline void build_prime(){
//	memset(vis,1,sizeof(vis));
//	vis[1]=0;
//	for (int i=2;i<=sqrt(maxx-5)+1;i++) if (vis[i])
//	for (int j=2;j<=(maxx-5)/i;j++) vis[i*j]=0;
//}
inline void build_prime(){
	int totPrimes=0;
	memset(vis,1,sizeof(vis));
	for (int i=2;i<=maxx-5;i++){
		if (vis[i]) primes[totPrimes++]=i;
		for (int j=0;i*primes[j]<=maxx-5;j++){
			vis[i*primes[j]]=0;
			if (i%primes[j]==0) break;
		}
    }
}
inline void build_sum(){
	for (int i=2;i<=maxx-5;i++) sum[i]=sum[i-1]+vis[i];
}
int main(){
	t=read();
	build_prime();
	build_sum();
	for (int i=1;i<=t;i++) printf("%d\n",sum[read()]);
	return 0;
}
