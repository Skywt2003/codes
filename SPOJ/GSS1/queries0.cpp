#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
const int INF=1e8;
int n,a[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int q=read();
	while (q--){
		int x=read(),y=read();
		int ans=-INF;
		for (int i=x;i<=y;i++){
			int num=0;
			for (int j=i;j<=y;j++){
				num+=a[j];
				ans=max(ans,num);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}