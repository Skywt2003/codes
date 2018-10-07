#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=200005;
int n,m,d,ans=0;
int head=0,tail=0;
int que[maxn],blt[maxn];

struct Element{
	int x,id;
};

Element a[maxn],prt[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool cmp(Element aa,Element bb){
	return aa.x<bb.x;
}

int main(){
	n=read();m=read();d=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	head=tail=1;
	que[head]=1;blt[1]=1;ans=1;
	for (int i=2;i<=n;i++){
		if ((head<=tail)&&(a[i].x-a[que[head]].x>=d+1)){
			blt[i]=blt[que[head]];
			head++;
			que[++tail]=i;
		} else {
			que[++tail]=i;
			blt[i]=++ans;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) prt[i].x=a[i].id,prt[i].id=blt[i];
	sort(prt+1,prt+1+n,cmp);
	for (int i=1;i<=n;i++) printf("%d ",prt[i].id);
	printf("\n");
	return 0;
}