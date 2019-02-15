#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxk=55;
int K,x,n,m,ansx=-1,ansy=-1,ansd=0;
int fib[maxk];
int delta[3][3][3][3][maxk];

#define delta_cur delta[i][j][k][t]

inline void build_fib(){
	fib[1]=fib[2]=1;
	for (int i=3;i<=50;i++) fib[i]=fib[i-1]+fib[i-2];
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++)
	for (int k=0;k<3;k++)
	for (int t=0;t<3;t++){
		delta_cur[1]=delta_cur[2]=0;
		int s1=i,t1=j,s2=k,t2=t;
		for (int w=3;w<=50;w++){
			int news=s1,newt=t2;
			if (t1==1 && s2==2) delta_cur[w]++;
			s1=s2;t1=t2;  s2=news;t2=newt;
			delta_cur[w]+=delta_cur[w-1]+delta_cur[w-2];
		}
	}
}

char mkchr(int x){
	if (x==1) return 'A'; else
	if (x==2) return 'C';
	return 'X';
}

void write_answer(int i,int j,int k,int t,int ac1,int ac2){
	if (n!=1){
		if (i) putchar(mkchr(i));
		for (int ii=1;ii<=ac1;ii++) putchar('A'),putchar('C');
		for (int ii=1;ii<=n-2*ac1-(i>0)-(j>0);ii++) putchar('X');
		if (j) putchar(mkchr(j));
	} else putchar(mkchr(i));
	printf("\n");

	if (m!=1){
		if (k) putchar(mkchr(k));
		for (int ii=1;ii<=ac2;ii++) putchar('A'),putchar('C');
		for (int ii=1;ii<=m-2*ac2-(k>0)-(t>0);ii++) putchar('X');
		if (t) putchar(mkchr(t));
	} else putchar(mkchr(k));
	printf("\n");
}

signed main(){
	K=read();x=read();n=read();m=read();
	build_fib();

	for (int i=0;i<3;i++)
	for (int j=((n==1)?i:0);j<((n==1)?(i+1):3);j++)
	for (int k=0;k<3;k++)
	for (int t=((m==1)?k:0);t<((m==1)?(k+1):3);t++){
		for (int ac1=0;ac1<=(n-(i>0)-(j>0))/2;ac1++)
		for (int ac2=0;ac2<=(m-(k>0)-(t>0))/2;ac2++){
			if (fib[K-2]*ac1+fib[K-1]*ac2 + delta[i][j][k][t][K] == x){
				write_answer(i,j,k,t,ac1,ac2);
				return 0;
			}
		}
	}
	printf("Happy new year!\n");
	return 0;
}