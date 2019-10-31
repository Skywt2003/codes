#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3e5+5;

int n,k;
int p[maxn],q[maxn];
int a[maxn],b[maxn];
vector<int> vec;

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif

	n=read();k=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) q[i]=read();

	int num=-n;
	for (int i=1;i<=n;i++) a[p[i]]=num++;

	for (int i=1;i<=n;i++){
		if (k==0) {b[q[i]]=n;continue;}
		if (q[i]-1 <= k) k-=(q[i]-1),b[q[i]]=0; else {
			vec.clear();
			for (int j=1;j<q[i];j++) vec.push_back(a[j]);
			sort(vec.begin(),vec.end());
			b[q[i]]=-vec[k]; k=0;
		}
	}
	if (k>0) printf("No\n"); else {
		printf("Yes\n");
		for (int i=1;i<=n;i++) printf("%lld ",a[i]); printf("\n");
		for (int i=1;i<=n;i++) printf("%lld ",b[i]); printf("\n");
	}
	return 0;
}