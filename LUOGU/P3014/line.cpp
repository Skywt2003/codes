#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int n,m,a[maxn],b[maxn];
bool vis[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline long long llread(){
	long long ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*(long long)10+(long long)(ch-'0'),ch=getchar();
	return (long long)ret*f;
}
inline char read_ch(){
	char ch=getchar();
	while (ch!='P'&&ch!='Q') ch=getchar();
	return ch;
}
inline bool check(int L,int R){
	for (int i=L;i<=R;i++) if (vis[i]) return 1;
	return false;
}
int main(){
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	n=read();m=read();
	for (int k=1;k<=m;k++){
		char ch=read_ch();
		if (ch=='Q'){
			long long fac=1;
			for (int i=1;i<=n;i++) a[i]=read(),fac=fac*(long long)i;
			fac=(long long)fac/(long long)n;
			long long x=0;int cnt=n-1;
			for (int i=1;i<=n;i++){
				int now=0; //now表示这个排列里（从左到右）第i个数字之后有多少比这个数字小的数字
				for (int j=i+1;j<=n;j++) if (a[i]>a[j]) now++;
				x=(long long)x+(long long)now*(long long)fac;
				if (cnt) fac=(long long)fac/(long long)cnt--;
			}
			printf("%lld\n",++x);
		} else if (ch=='P'){
			long long x=llread();x--;long long fac=1;
			for (int i=2;i<n;i++) fac=fac*(long long)i;
			for (int i=n;i>=1;i--){
				a[n-i+1]=(long long)x/fac;
				x%=fac;
				if (i-1) fac=fac/(long long)(i-1); else fac=1;
			}
			memset(vis,0,sizeof(vis));
			for (int i=1;i<=n;i++){ //B[i]即i位上的数字 
				int cnt=0;b[i]=-1;
				for (int j=0;j<=n;j++){
					if (vis[j]) cnt++;
					if ((!vis[cnt+a[i]+1])&&(!check(j+1,cnt+a[i]))){
						vis[cnt+a[i]+1]=1;b[i]=cnt+a[i]+1;break;
					}
				}
			}
			for (int i=1;i<n;i++) printf("%d ",b[i]);printf("%d\n",b[n]);
		}
	}
	return 0;
}
