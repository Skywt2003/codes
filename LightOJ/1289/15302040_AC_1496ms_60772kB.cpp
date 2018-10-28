#include<cstdio>
#include<cstring>
#include<iostream>
#include<bitset>
using namespace std;
const int maxp=6000005,maxn=100000005;
const long long tt=(long long)1<<32;
int T,n,tot=0;
unsigned int ans,prime[maxp],mul[maxp];
bitset<maxn> vis;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return  ret*f;
}
inline long long qsm(long long a,int b){
	long long ret=1,w=(long long)a;
	while (b){
		if (b&1) ret=ret*w;
		if (ret>n) return -1;
		b>>=1;w=w*w;
	}
	return ret;
}
inline void MakePrime(){
	for (int i=2;i<=1e8;i++){
		if (!vis.test(i)) prime[++tot]=i;
		for (int j=1;j<=tot;j++){
			if (i*prime[j]>1e8) break;
			vis.set(i*prime[j]);
			if (i%prime[j]==0) break;
		}
	}
}
inline void BuildMul(){
	mul[0]=1;
	for (int i=1;i<=tot;i++) mul[i]=mul[i-1]*prime[i];
}
inline int Find(int x){
	int L=1,R=tot,ret=0,mid;
	while (L<=R){
		mid=((R-L)>>1)+L;
		long long now=qsm(prime[mid],x);
		if (now<=n&&now>0) ret=mid,L=mid+1; else R=mid-1;
	}
	return ret;
}
int main(){
	T=read();
	MakePrime();
	BuildMul();int cnt=0;
	while (T--){
		n=read();ans=1;cnt++;
		for (int k=1;1<<k<=n;k++){
			int now=Find(k);
			ans=ans*mul[now];
		}
		printf("Case %d: %u\n",cnt,ans);
	}
	return 0;
}