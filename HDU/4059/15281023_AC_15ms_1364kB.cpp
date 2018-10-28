#define CLEAR(x) memset(x,0,sizeof(x))
#define LL long long
#define MOD (tt)
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=100;
const long long tt=1e9+7;
const int inv30=233333335;
int T;
long long n;
vector<long long> yinzi;
inline long long llread(){
    long long ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=(long long)ret*10+ch-'0',ch=getchar();
    return (long long)ret*f;
}
inline void MakeYinzi(int n){
	yinzi.clear();
	for (int i=2;i*i<=n;i++) if (n%i==0){
		yinzi.push_back(i);
		while (n%i==0) n/=i;
	}
	if (n>1) yinzi.push_back(n);
}
inline long long Get4(long long x){
	long long ret= (long long)x*(x+1)%tt*(2*x+1)%tt*(3*x*x%tt+3*x%tt-1+tt)%tt;
	return ret;
}
inline long long Make(long long x){
	long long ret=Get4(n/x);
	return x*x%tt*x%tt*x%tt*ret%tt;
}
inline long long GetAnswer(long long n){
	MakeYinzi(n);
	long long ret=Get4(n);
	int s=1<<yinzi.size();
	for (int i=1;i<s;i++){
		long long now=1,cnt=0;
		for (int j=0;j<yinzi.size();j++) if (i&(1<<j)){
			now*=yinzi[j];
			cnt++;
		}
		if ((cnt&1)==0) ret=(ret+Make(now))%tt; else ret=(ret-Make(now)+tt)%tt;
	}
	return (ret*inv30)%tt;
}
int main(){
	T=llread();
	for (int t=1;t<=T;t++){
		n=llread();
		long long ans=GetAnswer(n);
		printf("%lld\n",ans);
	}
	return 0;
}
