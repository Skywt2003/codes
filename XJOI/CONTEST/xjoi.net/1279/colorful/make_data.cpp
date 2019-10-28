#include<bits/stdc++.h>

using namespace std;

const int maxn=1e6+5;

int n=1000,m,k;

class uniset{
	private:
		int fa[maxn];

	public:
		void init(int n){
			for (int i=1;i<=n;i++) fa[i]=i;
		}

		int getfa(int x){
			return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
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
	
	m=rand()%n+1;k=rand()%m+1; u.init(n);
	printf("%d %d %d\n",n,m,k);
	for (int i=1;i<=n;i++) printf("%d ",rand()%m+1); printf("\n");
	for (int i=1;i<n;i++){
		int x=rand()%n+1,y=rand()%n+1;
		while (u.getfa(x) == u.getfa(y)) x=rand()%n+1,y=rand()%n+1;
		printf("%d %d\n",x,y);
		u.merge(x,y);
	}
	return 0;
}