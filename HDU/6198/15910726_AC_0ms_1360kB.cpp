#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int tt=998244353;
int n;
struct Matrix{
	int a[3][3];
	void init(){
		memset(a,0,sizeof(a));
		a[0][0]=a[1][0]=a[0][1]=1;
		a[1][1]=0;
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
	Matrix operator *(Matrix b){
		Matrix c; c.clear();
		for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
		for (int k=0;k<2;k++)
			c.a[i][j]=((long long)c.a[i][j]+(long long)a[i][k]*b.a[k][j])%tt;
		return c;
	}
	Matrix operator ^(long long b){
		Matrix ret; ret.init();
		Matrix w;   w.clear();
		for (int i=0;i<2;i++)
		for (int j=0;j<2;j++) w.a[i][j]=a[i][j];
		while (b){
			if (b%2) ret=ret*w;
			b=b/2;w=w*w;
		}
		return ret;
	}
	void write(){
		for (int i=0;i<2;i++){
			for (int j=0;j<2;j++) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
};
int main(){
	while (~scanf("%d",&n)){
		n=2*n+2;
		Matrix a;a.init();
		a=a^n;
		printf("%d\n",a.a[1][0]-1);
	}
	return 0;
}