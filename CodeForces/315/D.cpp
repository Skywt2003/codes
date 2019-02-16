#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=105;

int n,m;
char a[maxn],b[maxn];
int f[maxn],nxt[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();m=read();
	scanf("%s%s",a+1,b+1);
	int len1=strlen(a+1),len2=strlen(b+1);
	for (int i=1;i<=len2;i++){
		nxt[i]=i;
		for (int j=1;j<=len1;j++){
			if (a[j]==b[nxt[i]]) nxt[i]++;
			if (nxt[i]==len2+1) nxt[i]=1,f[i]++;
		}
	}
	int ans=0,now=1;
	for (int i=1;i<=n;i++){
		ans+=f[now];now=nxt[now];
	}
	printf("%lld\n",ans/m);
	return 0;
}