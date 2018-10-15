#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=505;
int t,n,m,a[maxn],b[maxn],f[maxn][maxn],lst[maxn];
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
	freopen("lics.out","w",stdout);
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		m=read();
		for (int i=1;i<=m;i++) b[i]=read();
		int ans=0;
		memset(f,0,sizeof(f));memset(lst,0,sizeof(lst));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (a[i]==b[j]) f[i][j]=lst[j-1]+1; else f[i][j]=f[i-1][j];
				if (j!=1){
					if (b[j-1]<a[i+1]) lst[j-1]=max(lst[j-2],f[i][j-1]);
					else lst[j-1]=lst[j-2];
				}
				if (f[i][j]>ans) ans=f[i][j];
			}
			if (b[m]<a[i+1]) lst[m]=max(lst[m-1],f[i][m]); else lst[m]=lst[m-1];
		}
		printf("%d\n",ans);
		if (t) printf("\n"); 
	}
	return 0;
}
