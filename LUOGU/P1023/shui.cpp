#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int h,c,ans=-(1<<30),p[maxn],maxc,sub;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int getp(int x){
	if (x<=maxc) return p[x]; else
	return p[maxc]-(x-maxc)*sub;
}
inline void WriteLook(){
	for (int i=c;i<=maxc+2;i++) printf("X=%d  P[X]=%d\n",i,getp(i));
}
int main(){
	h=read();
	c=read();p[c]=read();
	int x=read(),y=read();
	while (x!=-1&&y!=-1){
		p[x]=y;
		x=read();y=read();
		if (x>maxc) maxc=x;
	}
	sub=read();
	int i=c,j=1;
	while (i<maxc){
		int j=i;
		while (p[j+1]==0&&j+1<maxc) j++;
		int evr=(p[i]-p[j+1])/(j+1-i);
		for (int k=i+1;k<=j;k++) p[k]=p[k-1]-evr;
		i=j+1;
	}
	for (int k=c;;k++){
		double now=(double)(k*getp(k)-(h-c)*getp(h))/(double)(getp(h)-getp(k));
		if (getp(h)>getp(k)){
			
		} else{
			
		}
		int nowint=(int)(now-1e8);
		if (ans<nowint) ans=nowint;
		if (getp(k)<=0) break;
	}
	printf("%d\n",ans);
	WriteLook();
	return 0;
}
