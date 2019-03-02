#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005,INF=1e9+1;

int n,k;
int a[maxn];
vector<pair<int,int> > ans,aans;
int sum,asum=INF;

int myabs(int x){return x<0?-x:x;}

signed main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=1000;i++){
		ans.clear();sum=0;
		int now=i;
		if (now!=a[1]) ans.push_back(make_pair(1,now-a[1])),sum++;
		for (int j=2;j<=n;j++){
			now+=k;
			if (now!=a[j]) ans.push_back(make_pair(j,now-a[j])),sum++;
		}
		if (sum<asum) aans=ans,asum=sum;
	}
	printf("%lld\n",asum);
	for (int i=0;i<(int)aans.size();i++){
		if (aans[i].second<0) putchar('-'); else putchar('+');printf(" ");
		printf("%lld %lld\n",aans[i].first,myabs(aans[i].second));
	}
	return 0;
}