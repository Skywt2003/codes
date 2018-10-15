#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5005;
int n,m;
struct StudentData{
	int id,sc;
}a[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool cmp(StudentData aa,StudentData bb){
	return (aa.sc>bb.sc||(aa.sc==bb.sc&&aa.id<bb.id));
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i].id=read(),a[i].sc=read();
	m=(int)((double)m*1.5);
	sort(a+1,a+1+n,cmp);
	printf("%d ",a[m].sc);
	int xx=a[m].sc;m=0;
	for (int i=1;i<=n;i++) if (a[i].sc>=xx) m++; else break;
	printf("%d\n",m);
	for (int i=1;i<=m;i++) printf("%d %d\n",a[i].id,a[i].sc);
	return 0;
}
