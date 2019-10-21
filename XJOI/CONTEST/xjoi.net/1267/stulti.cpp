#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;
const int maxn=2e5+5,maxe=4e5+5;

int n,m,q;
int a[maxn];
int ans[maxn],w[maxn];

class uniSet{
	private:
		int fa[maxn],num[maxn];
	public:
		void init(int n){for (int i=1;i<=n;i++) fa[i]=i,num[i]=1;}
		int getfa(int x){return (fa[x]==x)?x:fa[x]=getfa(fa[x]);}
		int getnum(int x){return num[getfa(x)];}
		void merge(int x,int y){x=getfa(x),y=getfa(y);(x!=y)?fa[x]=y,num[y]+=num[x],num[x]=0:0;}
};

uniSet u;
bool vis[maxn];

vector<pair<pair<int,int>,int> > vec;

vector<pair<int,int> > query;

struct point{double x,y;};
point que[maxn];
int head=0,tail=0;

double slope(point a,point b){return -(a.y-b.y)/(a.x-b.x);}
bool compare_pii_first (pair<int,int> aa,pair<int,int> bb){return aa.first < bb.first;}
bool compare_pii_second(pair<pair<int,int>,int> aa,pair<pair<int,int>,int> bb){return aa.second > bb.second;}

signed main(){
	memset(w,0x80,sizeof(w));

	n=read(); m=read(); q=read();
	for (int i=1;i<=n;i++) a[i]=read(),w[1]=max(w[1],a[i]);
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		vec.push_back(make_pair(make_pair(x,y),min(a[x],a[y])));
	}

	u.init(n);
	sort(vec.begin(),vec.end(),compare_pii_second);
	for (int i=0;i<vec.size();i++){
		u.merge(vec[i].first.first,vec[i].first.second);
		int nownum=u.getnum(vec[i].first.first);
		w[nownum]=max(w[nownum],vec[i].second);
	}

	for (int i=n-1;i>=1;i--) w[i]=max(w[i],w[i+1]);

	#ifdef DEBUG
		for (int i=1;i<=n;i++) printf("w[%lld] = %lld\n",i,w[i]);
	#endif

	head=1,tail=0;
	for (int i=1;i<=n;i++) if (w[i]!=NEG_INF){
		point now=(point){i,w[i]*i};
		while (head<tail && slope(que[tail-1],que[tail]) >= slope(que[tail-1],now)) tail--;
		que[++tail]=now;
	}

	for (int i=1;i<=q;i++)
		query.push_back(make_pair(read(),i));
	sort(query.begin(),query.end(),compare_pii_first);

	for (int i=0;i<query.size();i++){
		while (head<tail && slope(que[head],que[head+1]) < query[i].first) head++;
		ans[query[i].second]=query[i].first*que[head].x+que[head].y;
	}
	for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);

	// while (q--){
	// 	int b=read();
	// 	int ansnow=-INF;
	// 	for (int i=1;i<=n;i++) if (w[i]!=NEG_INF) ansnow=max(ansnow,(w[i]+b)*i);
	// 	printf("%lld\n",ansnow);
	// }
	return 0;
}