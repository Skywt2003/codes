#include<bits/stdc++.h>

using namespace std;

int n=300;

class uniSet{
	private:
		int fa[3005];

	public:
		void init(int n){
			for (int i=1;i<=n;i++) fa[i]=i;
		}

		int getfa(int x){
			return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
		}

		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x!=y) fa[x]=y;
		}
};

uniSet u;

signed main(){
	srand(time(NULL));

	printf("%d\n",n);  u.init(n);
	
	for (int i=1;i<n;i++){
		int x=rand()%n+1,y=rand()%n+1;
		while (u.getfa(x) == u.getfa(y)) x=rand()%n+1,y=rand()%n+1;
		u.merge(x,y); printf("%d %d\n",x,y);
	}

	for (int i=1;i<=n;i++){
		int l=rand()%n+1,r=rand()%n+1;
		if (l>r) swap(l,r);
		printf("%d %d %d\n",l,r,rand()%n+1);
	}

	return 0;
}