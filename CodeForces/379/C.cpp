#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3e5+5;
int n;
struct raiting{
	int num,id;
}a[maxn];

bool cmp(raiting aa,raiting bb){
	return aa.num<bb.num;
}

bool cmpid(raiting aa,raiting bb){
	return aa.id<bb.id;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i].num=read(),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for (int i=2;i<=n;i++){
		if (a[i].num<=a[i-1].num) a[i].num=a[i-1].num+1;
	}
	sort(a+1,a+1+n,cmpid);
	for (int i=1;i<=n;i++) printf("%lld ",a[i].num);
	printf("\n");
	return 0;
}