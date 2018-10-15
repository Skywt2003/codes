#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=105,maxlen=105,tt=10000;
int n;
struct Bigint{
	int len,a[maxlen];
	Bigint(){len=0;memset(a,0,sizeof(a));}
	Bigint operator =(int b){
		while (b) a[++len]=b%tt,b/=tt;
	}
	Bigint operator +(Bigint b){
		Bigint c;memset(c.a,0,sizeof(c.a));
		c.len=max(len,b.len);
		for (int i=1;i<=c.len;i++){
			c.a[i]+=a[i]+b.a[i];
			c.a[i+1]+=c.a[i]/tt;
			c.a[i]%=tt;
		}
		if (c.a[c.len+1]) c.len++;
		return c;
	}
	Bigint operator -(Bigint b){
		Bigint c;memset(c.a,0,sizeof(c.a));
		c.len=len;
		for (int i=1;i<=c.len;i++){
			c.a[i]+=a[i]-b.a[i]+tt;
			c.a[i+1]+=c.a[i]/tt-1;
			c.a[i]%=tt;
		}
		if (!c.a[c.len]) c.len--;
		return c;
	}
	Bigint operator *(int b){
		Bigint c;memset(c.a,0,sizeof(c.a));
		c.len=len;
		for (int i=1;i<=c.len;i++){
			c.a[i]+=a[i]*b;
			c.a[i+1]+=c.a[i]/tt;
			c.a[i]%=tt;
		}
		while (c.a[c.len+1]) c.len++;
		return c;
	}
	void write(){
		printf("%d",a[len]);
		for (int i=len-1;i>=1;i--) printf("%04d",a[i]);
	}
}f[4];
int main(){
	scanf("%d",&n);
	Bigint two;two=2;
	f[1]=1;f[2]=5;
	for (int i=3;i<=n;i++) f[i%4]=f[(i-1+4)%4]*3-f[(i-2+4)%4]+two;
	f[n%4].write();printf("\n");
	return 0;
}
