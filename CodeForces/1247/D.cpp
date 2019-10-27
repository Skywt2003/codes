#include<bits/stdc++.h>

#define int long long

#define pii pair<int,int>

using namespace std;

const int maxn=1e5+5;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int N=1e5;

int n,k;
int a[maxn];

int prime[maxn];
bool flag[maxn];

map<vector<pii>,int> hsh;

void build_prime(){
	memset(flag,true,sizeof(flag));
	flag[1]=false;
	for (int i=2;i<=N;i++){
		if (flag[i]) prime[++prime[0]]=i;
		for (int j=1;j<=prime[0];j++){
			if (i*prime[j] > N) break;
			flag[i*prime[j]]=false;
			if (i%prime[j]==0) break;
		}
	}
}

vector<pii> break_down(int x){
	vector<pii> ret; ret.clear();
	for (int i=1;i<=prime[0];i++) if (x%prime[i]==0){
		int cnt=0;
		while (x%prime[i]==0) cnt++,x/=prime[i];
		if (cnt%k) ret.push_back(make_pair(prime[i],cnt%k));
	} else if (x==1) break;
	return ret;
}

vector<pii> get_comp(vector<pii> &vec){
	vector<pii> ret=vec;
	for (int i=0;i<ret.size();i++) ret[i].second=k-ret[i].second;
	return ret;
}

int ans=0;

signed main(){
	n=read(); k=read();
	for (int i=1;i<=n;i++) a[i]=read();

	build_prime();

	for (int i=1;i<=n;i++){
		vector<pii> now=break_down(a[i]);
		vector<pii> com=get_comp(now);
		ans+=hsh[com]; hsh[now]++;
	}

	printf("%lld\n",ans);
	return 0;
}