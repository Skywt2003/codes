#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200005;
int n,h,sum[maxn],ans=0;
struct fly{
	int x,y;
}a[maxn];

struct dot{
	int x,f;
}d[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int check(int s,int x){
	int L=1,R=2*n;
	while (L<=R){
		int mid=((R-L)>>1)+L;
		if ((d[mid].x<=x)&&(x<=d[mid+1].x)){
			if (d[mid].f==-1) return sum[(mid+1)>>1]; else
			return sum[(mid+1)>>1]-(d[mid+1].x-x);
			// return sum[(mid+1)>>1];
		} else if (d[mid].x<=x) L=mid+1; else R=mid-1;
	}
	// printf("ERROR x=%d\n",x);
	return 0;
}

inline int find(int x,int i){
	int ret=-1;
	int L=x,R=d[n*2].x;
	while (L<=R){
		int mid=((R-L)>>1)+L;
		int c=check(x,mid)-sum[i-1];
		// printf("x=%d mid=%d c=%d\n",x,mid,c);
		if (c+h==mid) ret=mid-x,L=mid+1; else
		if (c+h<mid) R=mid-1; else L=mid+1;
	}
	return ret;
}

int main(){
	n=read();h=read();
	int tmp=0;
	for (int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		d[++tmp].x=a[i].x;d[tmp].f=1;
		d[++tmp].x=a[i].y;d[tmp].f=-1;
		sum[i]=sum[i-1]+a[i].y-a[i].x;
	}
	d[2*n+1].x=1<<30;
	for (int i=1;i<=n;i++){
		int now=find(a[i].x,i);
		printf("I=%d now=%d\n",i,now);
		ans=max(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}