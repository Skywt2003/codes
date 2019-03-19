#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=205;
char s[maxn];
int k,len;

signed main(){
	scanf("%s",s+1);k=read();
	len=strlen(s+1);
	int num1=0,num2=0,sum=0;
	for (int i=1;i<=len;i++){
		if (s[i]=='?') num1++; else
		if (s[i]=='*') num2++; else sum++;
	}
	if ((num2==0 && (k<sum-num1 || k>sum))  ||  (k<sum-num1-num2)){
		printf("Impossible\n");
		return 0;
	}
	int need=k-sum;
	for (int i=1;i<=len;i++) if (s[i]!='?'&&s[i]!='*'){
		if (i+1<=len && s[i+1]=='?'){
			if (need>=0) putchar(s[i]); else
			if (need<0) need++;
		} else if (i+1<=len && s[i+1]=='*'){
			if (need>0){
				for (int j=1;j<=need+1;j++) putchar(s[i]);
				need=0;
			} else if (need==0) putchar(s[i]); else if (need<0) need++;
		} else putchar(s[i]);
	}
	printf("\n");
	return 0;
}