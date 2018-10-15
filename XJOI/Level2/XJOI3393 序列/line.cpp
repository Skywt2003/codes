#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxx=35,maxn=100005;
int n,a[maxn],hsh[maxx],ans=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int f(int x){
	if (x==0) return 0;
	if (x&1) return f(x/2)+1; else return f(x/2);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),hsh[f(a[i])]++;
	for (int i=1;i<=n;i++) if (hsh[f(a[i])]>1) {int x=f(a[i]);ans+=hsh[x]*(hsh[x]-1);hsh[x]=0;}
	printf("%d\n",ans/2);
	return 0;
}
