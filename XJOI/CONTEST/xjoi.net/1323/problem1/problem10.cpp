#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;
const int tt=1e9+7;

int n,ans=0;

bool vis[maxn];
int p[maxn];

bool check(){
	int ret=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			ret+=p[i]>p[j];
	return ret&1^1;
}

void build_p(int x){
	if (x==n){
		ans+= check();
		return;
	}
	for (int i=1;i<=n;i++) if (!vis[i]){
		p[x+1]=i; vis[i]=true;
		build_p(x+1);
		vis[i]=false;
	}
}

signed main(){
	freopen("problem1.in","r",stdin);
	freopen("problem10.out","w",stdout);
	
	n=read();
	
	build_p(0);
	
	printf("The %lld",n);
	if (n%10 == 1) printf("st"); else
	if (n%10 == 2) printf("nd"); else
	if (n%10 == 3) printf("rd"); else
	printf("th");
	printf(" answer is %lld.\n",ans);
	return 0;
}
