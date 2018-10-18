#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=60,maxl=30;
int n,m,a[2][maxl];
int main(){
	freopen("cnm.in","r",stdin);
	freopen("cnm.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		memset(a,0,sizeof(a));
		int q=-1;char ch=getchar();while (ch==10||ch==13) ch=getchar();
		while (1){
			if (ch=='+') ch=getchar();
			char lt=ch;
			if (ch=='=') break; else
			if (ch=='?') {q=0,ch=getchar();continue;}
			ch=getchar();
			if (ch<'0'||ch>'9') {a[0][lt-'A']++;continue;}
			a[0][lt-'A']+=ch-'0';
			ch=getchar();
		}
		ch=getchar();
		while (1){
			if (ch=='+') ch=getchar();
			char lt=ch;
			if (ch==10||ch==13) break; else
			if (ch=='?') {q=1,ch=getchar();continue;}
			ch=getchar();
			if (ch<'0'||ch>'9') {a[1][lt-'A']++;continue;}
			a[1][lt-'A']+=ch-'0';
			ch=getchar();
		}
		bool nos=false,hvd=false;
		for (int j=0;j<26;j++) if ((q==0&&(a[0][j]>a[1][j]||a[1][j]-a[0][j]>9))||(q==1&&(a[0][j]<a[1][j]||a[0][j]-a[1][j]>9))){
			nos=true;
			break;
		} else if (a[0][j]!=a[1][j]) hvd=true;
		if (nos||(!hvd)){
			printf("No Solution\n");
			continue;
		}
		for (int j=0;j<26;j++){
			int x=a[1-q][j]-a[q][j];
			if (x==0) continue; else
			if (x==1) putchar(j+'A'); else
			if (x>1) putchar(j+'A'),putchar(x+'0');
		}
		printf("\n");
	}
	return 0;
}
