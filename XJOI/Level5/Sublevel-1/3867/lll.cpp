#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=55;
int n,m;
char s[maxn];
int dst[maxn][maxn];

int f[maxn][maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int read_option(){
	char ch=getchar();
	while (ch!='a'&&ch!='e'&&ch!='c') ch=getchar();
	return ch=='a'?0:(ch=='e'?1:2);
}

inline int read_char(){
	char ch=getchar();
	while (ch!=' ') ch=getchar();
	ch=getchar();
	return ch-'a';
}

inline void Floyd(){
	for (int k=0;k<=27;k++){
		for (int i=0;i<=27;i++) if (i!=k){
			for (int j=0;j<=27;j++) if (k!=j&&i!=j){
				dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
			}
		}
	}
}

signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	m=read();
	memset(dst,0x3f,sizeof(dst));
	for (int i=0;i<=27;i++) dst[i][i]=0;
	for (int i=1;i<=m;i++){
		int option=read_option();
		if (option==0){
			int ch=read_char();
			int num=read();
			dst[27][ch]=min(dst[27][ch],num);
		} else if (option==1){
			int ch=read_char();
			int num=read();
			dst[ch][27]=min(dst[ch][27],num);
		} else if (option==2){
			int ch1=read_char(),ch2=read_char();
			int num=read();
			dst[ch1][ch2]=min(dst[ch1][ch2],num);
		}
	}
	Floyd();
	for (int L=1;L<=2*n-1;++L){
		for (int i=1;i<=n-L;i++){
			int j=i+L;
			
		}
	}
}