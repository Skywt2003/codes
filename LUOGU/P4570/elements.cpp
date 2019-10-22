#include<bits/stdc++.h>

#define int long long
#define pii pair<int,int>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;

int n;

class basis{
	private:
		int p[70],w[70];

	public:
		basis(){
			memset(p,0,sizeof(p));
		}

		bool insert(int x){
			for (int i=62;i>=0;i--) if (x&(1ll<<i)){
				if (!p[i]) {p[i]=x; return true;}
				x^=p[i];
			}
			return false;
		}

		int query(){
			int ret=0;
			for (int i=62;i>=0;i--) if ((ret^p[i])>ret) ret^=p[i];
			return ret;
		}
};

basis b;

pii magic[maxn];

bool compare_pii_second(pii aa,pii bb){
	return aa.second > bb.second;
}

int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) magic[i].first=read(),magic[i].second=read();
	sort(magic+1,magic+1+n,compare_pii_second);

	for (int i=1;i<=n;i++) if (b.insert(magic[i].first)) ans+=magic[i].second;
	printf("%lld\n",ans);
	return 0;
}

