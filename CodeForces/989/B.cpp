#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn=2005;
int n,p;
char s[maxn];
char q[maxn];
char ans[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	n=read();p=read();
	scanf("%s",s+1);
	memset(q,'.',sizeof(q));
	memset(ans,'.',sizeof(ans));
	bool flg=false;
	for (int i=1;i<=n;i++){
		if (s[i]!='.'){
			ans[i]=s[i];
			if (q[(i-1)%p+1]=='.') q[(i-1)%p+1]=s[i]; else
			if (q[(i-1)%p+1]!=s[i]) flg=true;
		}
	}
	for (int i=1;i<=n;i++){
		if (ans[i]=='.'){
			if (q[(i-1)%p+1]=='.') q[(i-1)%p+1]=ans[i]='0'; else {
				ans[i]=(q[(i-1)%p+1]=='0')?'1':'0';
				flg=true;
			}
		}
	}
	if (!flg){
		printf("No\n");
		return 0;
	}
	for (int i=1;i<=n;i++) putchar(ans[i]);
	return 0;
}