#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

int random(int x){
	return ((rand()<<15)+(rand()))%x;
}

const int maxn=1005;

int n=1000;

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
	freopen("problem3.in","w",stdout);
	srand(GetTickCount());
	
	printf("%d\n",n);
	for (int i=1;i<=n;i++) printf("%d ",random(1000)); printf("\n");
	
	u.init(n);
	for (int i=1;i<n;i++){
		int x=random(n)+1,y=random(n)+1;
		while (u.getfa(x) == u.getfa(y)) x=random(n)+1,y=random(n)+1;
		printf("%d %d %d\n",x,y,random(1000));
		u.merge(x,y);
	}
	return 0;
}
