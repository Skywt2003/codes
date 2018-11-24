#include<cstdio>
#include<cstring>
#include<iostream>

#define int long long
using namespace std;

const int maxn=5;
const int M=23*28*33;

// Spread 28
// 1 3 5 9 11 13 15 17 19 23 25 27

// Spread 33
// 1 2 4 5 7 8 10 13 14 16 17 19 20 23 25 26 28 29 31 32

int p;
int a[maxn];
const int m[5]={23,28,33,0,0};
const int Mi[5]={28*33,23*33,23*28,0,0};
int t[5];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int qsm(int a,int b){
	int ret=1,w=a%M;
	while (b){
		if (b&1) ret=ret*w%M;
		b>>=1;w=w*w%M;
	}
	return ret;
}

signed main(){
	t[0]=qsm(Mi[0],m[0]-2);
	t[1]=qsm(Mi[1],11);
	t[2]=qsm(Mi[2],19);
	int case_num=0;
	for (;;){
		case_num++;
		a[0]=read();a[1]=read();a[2]=read();p=read();
		if (a[0]==-1 && a[1]==-1 && a[2]==-1 && p==-1) break;
		int ans=0;
		for (int i=0;i<3;i++) ans+=a[i]*t[i]*Mi[i]%M;
		ans=(ans-p+M)%M;
		printf("Case %lld: the next triple peak occurs in %lld days.\n",case_num,((ans)?(ans):(M)));
	}
	return 0;
}