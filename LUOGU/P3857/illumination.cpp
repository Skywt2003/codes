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

int n,m;

class linerBase{
	private:
		int p[70];

	public:
		linerBase(){
			memset(p,0,sizeof(p));
		}

		bool insert(int x){
			for (int i=62;i>=0;i--) if (x&(1ll<<i)){
				if (!p[i]) {p[i]=x;return true;}
				x^=p[i];
			}
			return false;
		}

		int count(){
			int ret=0;
			for (int i=62;i>=0;i--) ret+=p[i]>0;
			return ret;
		}
};

linerBase lb;

char s[maxn];

signed main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		scanf("%s",s);
		int num=0;
		for (int j=0;j<n;j++) if (s[j]=='O') num+=1ll<<j;
		lb.insert(num);
	}
	printf("%lld\n",(1ll<<lb.count())%2008);
	return 0;
}