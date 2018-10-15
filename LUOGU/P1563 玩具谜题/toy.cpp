#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,m;
struct ToysData{
	int face;  //face=0:inside,l--r++; face=1:outside,l++r--.
	string name;
}a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();m=read();
	for (int i=0;i<n;i++){
		a[i].face=read();
		cin>>a[i].name;
	}
	int now=0;
	for (int i=1;i<=m;i++){
		int x=read(),y=read(); //x==0:left; x==1;right.
		if (x==0){
			if (a[now].face==0) now=(now-y+n)%n; else
			if (a[now].face==1) now=(now+y)%n;
		} else if (x==1){
			if (a[now].face==0) now=(now+y)%n; else
			if (a[now].face==1) now=(now-y+n)%n;
		}
	}
	cout<<a[now].name;
	return 0;
}
