#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=998244353;

const int maxn=1e6+5;

int n,m,k;
vector<int> fuck[maxn];

int abbs(int x){
	return (x<0)?-x:x;
}

namespace subtask1and4{ // Case K=0 & K=1 (uninclude N=1 or 2)
	signed main(){
		puts("0");
		return 0;
	}
};

namespace subtask2{ // Case N=1
	signed main(){
		puts("1");
		return 0;
	}
}

namespace subtask3{ // Case N=2
	signed main(){
		if (k==0 || fuck[1].size()!=0 || fuck[2].size()!=0) puts("0");
		else puts("1");
		return 0;
	}
}

namespace subtask6{
	signed main(){
		int ans=0,flg=1;
		fuck[0]=fuck[1];
		for (int i=0;i<=n && flg;i+=2)
			for (int j=0;j<fuck[i].size() && flg;j++)
				if (fuck[i][j] == i+2) {flg=0;break;}
		int ls=(n&1)?n:n-1,rs=(n&1)?n-1:n;
		for (int j=0;j<fuck[rs].size() && flg;j++) if (fuck[rs][j]==ls) {flg=0;break;}
		for (int i=ls;i>=1 && flg;i-=2)
			for (int j=0;j<fuck[i].size() && flg;j++)
				if (fuck[i][j] == i-2) {flg=0;break;}
		ans+=flg;
		
		flg=1;
		for (int i=1;i<=n && flg;i+=2)
			for (int j=0;j<fuck[i].size() && flg;j++)
				if (fuck[i][j] == i+2) {flg=0;break;}
		ls=(n&1)?n-1:n,rs=(n&1)?n:n-1;
		for (int j=0;j<fuck[rs].size() && flg;j++) if (fuck[rs][j]==ls) {flg=0;break;}
		for (int i=ls;i>=1 && flg;i-=2)
			for (int j=0;j<fuck[i].size() && flg;j++)
				if (fuck[i][j] == i-2) {flg=0;break;}
		ans+=flg;
		
		printf("%lld\n",ans);
		return 0;
	}
};

namespace subtaskOther{
	const int MaxN=1005;
	bool vis[MaxN],cant[MaxN][MaxN];
	int ans=0;

	void DFS(int step,int num){
		if (step==n){
			if (cant[num][1] || abbs(num-1)>k) return;
			ans=(ans+1)%tt; return;
		}
		for (int i=num-3;i<=num+3;i++) if (i>=1 && i<=n && !vis[i] && !cant[num][i])
			vis[i]=true,DFS(step+1,i),vis[i]=false;
	}

	signed main(){
		for (int i=1;i<=n;i++)
			for (int j=0;j<fuck[i].size();j++)
				cant[i][fuck[i][j]]=true;
		
		#ifdef DEBUG
			printf("Fuck here\n");
		#endif
	
		memset(vis,0,sizeof(vis));
		vis[1]=true; DFS(1,1);
		
		printf("%lld\n",ans);
		return 0;
	}
};

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); m=read(); k=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		if (abbs(x-y) > k) continue;
		fuck[x].push_back(y);
	}
	
	if (n==1) return subtask2::main();
	if (k==0 || k==1) return subtask1and4::main(); else
	if (k==2) return subtask6::main(); else
	return subtaskOther::main();
}
