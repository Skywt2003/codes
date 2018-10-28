#define CLEAR(x) memset(x,0,sizeof(x))
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=50;
int T;
long long a,b,n;
vector<long long> yinzi;
inline long long llread(){
    long long ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=(long long)ret*10+ch-'0',ch=getchar();
    return (long long)ret*f;
}
inline void MakeYinzi(long long n){
	yinzi.clear();
	for (long long i=2;i*i<=n;i++) if (n%i==0){
		yinzi.push_back(i);
		while (n%i==0) n/=i;
	}
	if (n>1) yinzi.push_back(n);
}
inline long long GetAnswer(long long x,long long n){
	long long ret=0;
	MakeYinzi(n);
	long long s=1<<yinzi.size();
	for (int i=1;i<s;i++){
		long long now=1,cnt=0;
		for (long long j=0;j<yinzi.size();j++) if (i&(1<<j)){
			now*=yinzi[j];
			cnt++;
		}
		if (cnt&1) ret+=x/now; else ret-=x/now;
	}
	return x-ret;
}
int main(){
	T=llread();
	for (int t=1;t<=T;t++){
		a=llread();b=llread();n=llread();
		long long ans=GetAnswer(b,n)-GetAnswer(a-1,n);
		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}