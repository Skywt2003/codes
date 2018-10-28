#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=3000005,N=3000000;
int T,n,prime[maxn];
bool vis[maxn];
unsigned long long f[maxn];
unsigned int phi[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return  ret*f;
}
inline void BuildPhi(){ // 线性筛法求欧拉函数，黑科技！
	phi[1]=1;
	memset(vis,1,sizeof(vis));
	vis[1]=false;
	for (int i=2;i<=N;i++){
		if (vis[i]){
			phi[i]=i-1;
			prime[++prime[0]]=i;
		}
		for (int j=1;j<=prime[0];j++){
			if (i*prime[j]>N) break;
			vis[i*prime[j]]=false;
			if (i%prime[j]) phi[i*prime[j]]=(prime[j]-1)*phi[i];
			else {phi[i*prime[j]]=prime[j]*phi[i];break;}
		}
	}
}
inline void BuildSum(){
	for (int i=1;i<=N;i++){
		for (int j=i;j<=N;j+=i) f[j]+=(unsigned long long)phi[i]*i/2*j; // i 作为因子
		f[i]=f[i-1]+f[i]; // i 之前的一定都求好了，干脆累加起来
	}
}
int main(){
	T=read();
	BuildPhi();
	BuildSum();
	for (int t=1;t<=T;t++){
		n=read();
		printf("Case %d: %llu\n",t,f[n]);
	}
	return 0;
}