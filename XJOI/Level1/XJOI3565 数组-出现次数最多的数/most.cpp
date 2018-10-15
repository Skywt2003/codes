#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=25;
int n,a[maxn],hsh[maxn],maxcnt=0,ans=-1;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read();
		bool flg=1;
		for (int j=1;j<=a[0];j++) if (a[j]==x){ // I am so clever!!!!!
			hsh[j]++;flg=0;break;
		}
		if (!flg) continue;
		a[++a[0]]=x;hsh[a[0]]=1;
	}
	for (int i=1;i<=a[0];i++) if (hsh[i]>maxcnt) maxcnt=hsh[i],ans=a[i];
	printf("%d\n",ans);
	return 0;
}
