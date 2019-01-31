#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>

using namespace std;

const int maxn=305;
int INF;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,N;
pair<int,int> a[maxn];
int f[maxn][maxn*maxn];

vector<int> vec;
int num[maxn*maxn];
map<int,int> key;

inline void make_yinzi(int x){
	vec.push_back(x);
	for (int i=2;i<=sqrt(x);i++) if (x%i==0){
		vec.push_back(i);vec.push_back(x/i);
	}
}

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i].first=read();
	for (int i=1;i<=n;i++) a[i].second=read();

	vec.clear();vec.push_back(1);vec.push_back(0);
	for (int i=1;i<=n;i++) make_yinzi(a[i].first);
	sort(vec.begin(),vec.end());unique(vec.begin(),vec.end());
	N=(int)vec.size();
	for (int i=1;i<=N;i++) num[i]=vec[i-1],key[num[i]]=i;
	
	memset(f,63,sizeof(f));INF=f[0][0];
	f[0][key[0]]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			for (int k=1;k<=N;k++) if (f[j-1][k]!=INF){
				int nxt=key[gcd(a[i].first,num[k])];
				f[j][nxt]=min(f[j][nxt],f[j-1][k]+a[i].second);
			}
		}
	}

	int ans=INF;
	for (int i=1;i<=n;i++) ans=min(ans,f[i][key[1]]);
	printf("%d\n",(ans==INF)?-1:ans);
	return 0;
}