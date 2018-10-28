#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt,now,id,a[5005], p[5005], ans[5005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]==0) continue;
		for(int j=2;j<=10000;j++){
			while(a[i]%(j*j)==0) a[i]/=j*j;
		}
	}
	for(int i=1;i<=n;i++) p[i]=a[i];
	sort(p+1,p+n+1);
	cnt=unique(p+1,p+n+1)-(p+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+cnt+1,a[i])-p;
	id=lower_bound(p+1,p+cnt+1,0)-p;
	if(p[id]) id=-(1<<30);
	for(int i=1;i<=n;i++){
		now=0;
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++){
			if(a[j]!=id&&p[a[j]]==0) now++;
			p[a[j]]=1;
			ans[max(now,1)]++;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
