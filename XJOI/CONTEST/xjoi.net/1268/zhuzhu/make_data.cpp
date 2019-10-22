#include<bits/stdc++.h>

using namespace std;

int n=4,m=5;

bool vis[105][105];

struct edge{
    int x,y,w;
};
edge a[105];

class uniSet{
	private:
		int fa[105];
	
	public:
		void init(int n){
			for (int i=0;i<=n;i++) fa[i]=i;
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

bool compare_w(edge aa,edge bb){
	return aa.w < bb.w;
}

int Kruskal(){
	sort(a+1,a+1+m,compare_w);
	int sum=0;
	u.init(n);
	for (int i=1;i<=m;i++){
		int x=u.getfa(a[i].x),y=u.getfa(a[i].y);
		if (x==y) continue;
		sum+=a[i].w;
		u.merge(x,y);
	}
	return sum;
}

signed main(){
    srand(time(NULL));
    printf("1\n");
    
    printf("%d %d\n",n,m);

    for (int i=1;i<=m;i++){
        a[i].x=rand()%n+1,a[i].y=rand()%n+1;
        while (a[i].x==a[i].y || vis[a[i].x][a[i].y]) a[i].x=rand()%n+1,a[i].y=rand()%n+1;
        vis[a[i].x][a[i].y]=vis[a[i].y][a[i].x]=true;
        a[i].w=rand()%10;
    }

    printf("%d\n",Kruskal());

    for (int i=1;i<=m;i++) printf("%d %d %d\n",a[i].x,a[i].y,a[i].w);
    return 0;
}