#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
const int maxn=100005;
int n,x,y,h1,h2,ans=0,a[maxn];
struct Element{
	int x,id;
	bool operator <(Element b)const{
		return x<b.x;
	}
};
priority_queue <Element> heap;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	n=read();x=read();y=read();h1=read();h2=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int now1=h1,now2=h2,lst=0;
	for (int i=1;i<=n;i++){
		now2-=x;
		if (now2<=0){
			printf("Win\n%d\n",i);
			return 0;
		}
		now1-=a[i];heap.push((Element){a[i],i});
		if (now1<=0){
			ans=h2-now2;lst=i;
			break;
		}
	}
	if (now1>0) {printf("Lose\n%d\n",ans);return 0;}
	while (!heap.empty()){
		Element now=heap.top();heap.pop();
		now1+=max(y,now.x);
		now2+=x;
		for (int i=lst+1;i<=n;i++){
			now2-=x;
			if (now2<=0){
				printf("Win\n%d\n",i);
				return 0;
			}
			now1-=a[i];heap.push((Element){a[i],i});
			if (now1<=0){
				ans=max(ans,h2-now2);lst=i;
				break;
			}
			if (i==n) ans=max(ans,h2-now2),lst=n;
		}
		if (lst>=n) break;
	}
	printf("Lose\n%d\n",ans);
	return 0;
}