#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;
int n,x1,x2,y1[maxn],y2[maxn];
int k[maxn],b[maxn];

struct line{
	int y1,y2;
}a[maxn];

bool cmp(line aa,line bb){
	return (aa.y1<bb.y1)||(aa.y1==bb.y1 && aa.y2<bb.y2);
}

signed main(){
	n=read();x1=read();x2=read();
	for (int i=1;i<=n;i++) k[i]=read(),b[i]=read(),a[i].y1=k[i]*x1+b[i],a[i].y2=k[i]*x2+b[i];
	sort(a+1,a+1+n,cmp);
	int maxb=a[1].y2;
	for (int i=2;i<=n;i++){
		if (a[i].y2<maxb){
			printf("YES\n");
			return 0;
		}
		maxb=a[i].y2;
	}
	printf("NO\n");
	return 0;
}