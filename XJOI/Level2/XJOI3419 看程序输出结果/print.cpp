#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10005;
int n,k,tt,sum=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int qsm(int a,int b){
	int w=a%tt,ret=1;
	while (b){
		if (b&1) ret=(ret*w)%tt;
		b>>=1;w=(w*w)%tt;
	}
	return ret;
}
int main(){
	n=read();k=read();tt=read();
	for (int i=1;i<=n;i++) sum=(sum+read()%tt)%tt;
	int tmp=(qsm(n,k-1)*(k%tt))%tt;
	sum=(tmp*sum)%tt;
	printf("%d\n",sum);
	return 0;
}
