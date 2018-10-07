#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long maxn=305;
long long n,x[maxn],delta[maxn],fst=-1,ans=0;

inline long long read(){
	long long ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	n=read();
	for (long long i=1;i<=n;i++) x[i]=read();
	for (long long i=1;i<=n;i++) delta[i]=read();
	long long need=0,sum=0;
	for (long long i=1;i<=n;i++){
		if ((fst==-1)&&(delta[i]<0)) fst=x[i];
		need+=(delta[i]<0)?(-delta[i]):(0);
		sum+=(delta[i]>0)?(delta[i]):(0);
		if (sum>=need&&need!=0){
			ans+=2*(x[i]-fst);
			sum-=need,need=0;
			fst=-1;
		}
		ans+=x[i]-x[i-1];
	}
	printf("%d\n",ans);
	return 0;
}