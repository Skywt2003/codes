#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;

class linerBase{
	private:
		int a[65];

	public:
		linerBase(){
			memset(a,0,sizeof(a));
		}

		bool insert(int x){
			for (int i=60;i>=0;i--) if (x&(1ll<<i)){
				if (!a[i]) {a[i]=x;return true;}
				x^=a[i];
			}
			return false;
		}
};

int n,ans=0,a[maxn];

linerBase lb;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,greater<int>());
	for (int i=1;i<=n;i++) if (!lb.insert(a[i])) ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}