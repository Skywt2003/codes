#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=200005;
const int tt=10007;

int n;

int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
int w[maxn];

int ans1=0,ans2=0;

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void make_answer(int x,int fa){
	vector<int> vec; vec.clear();
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		if (fa!=-1) ans1=max(ans1,w[to[i]]*w[fa]),ans2=(ans2+w[to[i]]*w[fa]%tt)%tt;
		vec.push_back(w[to[i]]);
	}
	sort(vec.begin(),vec.end());
	if (vec.size() >= 2) ans1=max(ans1,vec[vec.size()-1]*vec[vec.size()-2]);
	int sum=0;
	for (int i=0;i<vec.size();i++){
		ans2=(ans2+sum*vec[i]%tt)%tt;
		sum=(sum+vec[i])%tt;
	}
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa) make_answer(to[i],x);
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
	}
	for (int i=1;i<=n;i++) w[i]=read();

	make_answer(1,-1);

	printf("%d %d\n",ans1,ans2*2%tt);
	return 0;
}