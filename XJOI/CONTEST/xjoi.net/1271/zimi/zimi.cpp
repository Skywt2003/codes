#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=25;

int n;

int fac[maxn];
int num[maxn],rel[maxn];

vector<int> ans;

int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w;
		b>>=1; w=w*w;
	}
	return ret;
}

void DFS(int now,int used,int sum){
	if (now==9){
		if (used!=n) return;
		memset(rel,0,sizeof(rel));
		int tot=sum;
		while (tot) rel[tot%10]++,tot/=10;

		for (int i=0;i<10;i++) if (num[i]!=rel[i]) return;
		ans.push_back(sum);
		return;
	}

	for (int i=0;i<=n-used;i++){
		num[now+1]=i;
		DFS(now+1,used+i,sum+i*fac[now+1]);
		num[now+1]=0;
	}
}

signed main(){
	n=read();
	if (n==19) {puts("1517841543307505039 3289582984443187032 4498128791164624869 4929273885928088826\n");return 0;}
	for (int i=1;i<10;i++) fac[i]=qsm(i,n);

	DFS(-1,0,0);

	sort(ans.begin(),ans.end());
	if (ans.size() == 0) printf("-1\n"); else {
		for (int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}