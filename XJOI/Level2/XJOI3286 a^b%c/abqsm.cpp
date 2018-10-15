#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a,b,tt;
inline int qsm(int a,int b){
	int w=a,ret=1;
	while (b){
		if (b&1) ret=((long long)ret*w)%tt;
		b>>=1;w=((long long)w*w)%tt;
	}
	return ret;
}
int main(){
	scanf("%d%d%d",&a,&b,&tt);
	printf("%d\n",qsm(a,b)%tt);
	return 0;
}
