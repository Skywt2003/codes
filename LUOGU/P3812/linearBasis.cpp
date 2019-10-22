#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55;

int n;

class basis{
	private:
		int p[70];

	public:
		basis(){
			memset(p,0,sizeof(p));
		}

		void insert(int x){
			for (int i=62;i>=0;i--) if (x&(1ll<<i)){
				if (!p[i]) {p[i]=x; break;}
				x^=p[i];
			}
		}

		int query(){
			int ret=0;
			for (int i=62;i>=0;i--) if ((ret^p[i])>ret) ret^=p[i];
			return ret;
		}
};

basis b;

signed main(){
	n=read();

	for (int i=1;i<=n;i++) b.insert(read());
	printf("%lld\n",b.query());

	return 0;
}