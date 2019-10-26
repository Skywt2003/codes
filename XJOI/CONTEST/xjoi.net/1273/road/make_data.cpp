#include<bits/stdc++.h>

using namespace std;

const int maxn=10;

int n=7;

class uniset{
	private:
		int fa[maxn];

	public:
		void init(int n){
			for (int i=1;i<=n;i++) fa[i]=i;
		}

		int getfa(int x){
			return (x==fa[x])?x:fa[x]=getfa(fa[x]);
		}

		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x==y) return;
			fa[x]=y;
		}
};

uniset u;

signed main(){
	srand(time(NULL));
	printf("%d\n",n);
	u.init(n);
	for (int i=1;i<n;i++){
		int x=rand()%n+1,y=rand()%n+1;
		while (u.getfa(x) == u.getfa(y)) x=rand()%n+1,y=rand()%n+1;
		u.merge(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}