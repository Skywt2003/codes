#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5;
int n,m;
int s[maxn],a[maxn];
vector<int> vec;

signed main(){
	freopen("pigeon.in","r",stdin);
	freopen("pigeon.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++) s[i]=read();
	for (int i=1;i<=n/2;i++) swap(s[i],s[n-i+1]);
	while (m--){
		int opt=read();
		if (opt==1) n--;
		else if (opt==2) s[++n]=read();
		else if (opt==3){
			int x=read(),y=read(),k=read();
			for (int i=1;i<=n;i++) a[i]=s[n-i+1];
			vec.clear();
			for (int i=x;i<=y;i++) vec.push_back(a[i]);
			sort(vec.begin(),vec.end());
			printf("%lld\n",vec[k-1]);
		}
	}
	return 0;
}