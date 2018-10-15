#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n;
long long ans=0;
struct WorkInfo{
	int t,p;
}a[maxn];
priority_queue <WorkInfo> heap;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool cmp(WorkInfo aa,WorkInfo bb){
	return ((aa.t<bb.t)||(aa.t==bb.t&&aa.p>bb.p));
}
inline bool operator <(WorkInfo aa,WorkInfo bb){
	return aa.p>bb.p;
}
int main(){
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i].t=read(),a[i].p=read();
	sort(a+1,a+1+n,cmp);
	int tme=0;
	for (int i=1;i<=n;i++)
		if (tme+1<=a[i].t) heap.push(a[i]),tme++,ans+=(long long)a[i].p; else
		if (heap.top().p<a[i].p) ans+=(long long)a[i].p-(long long)heap.top().p,heap.pop(),heap.push(a[i]);
	printf("%lld\n",ans);;
	return 0;
}
