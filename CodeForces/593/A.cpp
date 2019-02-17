#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105,maxlen=1005;

int n,ans=0,len[maxn];
char a[maxn][maxlen];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1),len[i]=strlen(a[i]+1);
	for (char c1='a';c1<='z';c1++){
		for (char c2='a';c2<='z';c2++) if (c1!=c2){
			int now=0;
			for (int i=1;i<=n;i++){
				bool flg=true;
				for (int k=1;k<=len[i];k++) if (a[i][k]!=c1 && a[i][k]!=c2) {flg=false;break;}
				if (flg) now+=len[i];
			}
			ans=max(ans,now);
		}
	}
	printf("%lld\n",ans);
	return 0;
}