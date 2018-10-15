#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
const char fg[5]={'o','i','e','r',' '};
int n,len;
char s[maxn];
int main(){
	scanf("%d",&n);
	for (int k=1;k<=n;k++){
		len=0;
		char ch=getchar();while (ch==10||ch==13) ch=getchar();
		while (ch!=10&&ch!=13&&ch!=-1){s[++len]=ch;ch=getchar();}
		if (s[1]==' '||s[len]==' '){printf("NO\n");continue;}
		s[++len]=' ';
		if (len%5){printf("NO\n");continue;}
		bool flg=1;
		for (int i=1;i<=len;i+=5){
			for (int j=i;j<=i+4;j++)
				if (s[j]!=fg[j-i]){flg=false;break;}
			if (!flg) break;
		}
		if (flg) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}
