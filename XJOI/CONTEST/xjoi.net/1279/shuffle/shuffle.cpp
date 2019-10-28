#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=15;
const int tt=998244353;

int n,k,a[maxn],tmp[maxn],nxt[maxn];
int p[maxn];
bool used[maxn];

int ans=0;
int tpr[maxn];

void change(){
	for (int i=1;i<=n;i++) nxt[p[i]]=tmp[i];
	for (int i=1;i<=n;i++) tmp[i]=nxt[i];
}

bool equal(){
	for (int i=1;i<=n;i++) if (tmp[i]!=i) return false;
	return true;
}

void DFS(int x){
	if (x==n){
		int nk=k;
		for (int i=1;i<=n;i++) tmp[i]=i;
		bool flg=false;
		for (int i=1;i<=nk;i++){
			change();
			if (equal()) {nk%=i,flg=true;break;}
		}
		if (flg){
			for (int i=1;i<=n;i++) tmp[i]=i;
			for (int i=1;i<=nk;i++) change();
		}

		for (int i=1;i<=n;i++) if (tmp[i]!=a[i]) return;
		ans=(ans+1)%tt;
		for (int i=1;i<=n;i++) tpr[i]=p[i];
		return;
	}
	for (int i=1;i<=n;i++) if (!used[i]){
		used[i]=true; p[x+1]=i;
		DFS(x+1);
		used[i]=false;
	}
}

signed main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();

	DFS(0);

	printf("1\n%lld\n",ans?ans:-1);
	for (int i=1;i<=n;i++) printf("%lld ",tpr[i]); printf("\n");
	return 0;
}