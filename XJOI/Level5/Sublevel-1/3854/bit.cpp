#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=55,maxlen=32+5;
int n,a[maxn];
bool vis[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	memset(vis,true,sizeof(vis));
	int ans=0;
	for (int j=31;j>=0;j--){
		bool flg=false;
		for (int i=1;i<=n;i++){
			if ((!vis[i])&&(a[i]>(1<<j))){
				ans+=1<<j;
				flg=true;
				break;
			}
		}
		int k=-1;
		if (!flg) for (int i=1;i<=n;i++){
			if (vis[i]&&(a[i]&(1<<j))){
				ans+=1<<j;k=i;
				flg=true;
				break;
			}
		}
		if (flg){
			for (int i=1;i<=n;i++) if ((i!=k)&&(vis[i])&&(a[i]&(1<<j))) vis[i]=false;
			// putchar('1');
		}// else putchar('0');
	}
	printf("%lld\n",ans);
	return 0;
}