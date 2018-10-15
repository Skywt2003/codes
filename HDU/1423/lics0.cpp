#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=505;
int t,n,m,a[maxn],b[maxn],f[maxn][maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int max(int x,int y){
	if (x>y) return x; else return y;
}
int main(){
	freopen("lics.in","r",stdin);
	freopen("lics0.out","w",stdout);
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		m=read();
		for (int i=1;i<=m;i++) b[i]=read();
		int ans=0;
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (a[i]==b[j]){
					f[i][j]=1;
					for (int k=1;k<j;k++) if (b[k]<b[j]) f[i][j]=max(f[i][j],f[i-1][k]+1);
				} else f[i][j]=f[i-1][j];
				if (f[i][j]>ans) ans=f[i][j];
			}
		}
		printf("%d\n",ans);
		if (t) printf("\n"); 
	}
	return 0;
}
