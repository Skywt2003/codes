#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=155,maxnum=10;
int n;
bool vis[maxn];
vector<int> vec;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void DFS(vector<int> now){
	if (now.size()==1){
		vis[now[0]]=true;
		return;
	}
	vector<int> nxt;
	for (int i=0;i<now.size()-1;i++){
		nxt.clear();
		for (int j=0;j<now.size();j++) if (j!=i && j!=i+1) nxt.push_back(now[j]); else if (j==i) nxt.push_back(now[j]+now[j+1]>>1);
		DFS(nxt);
	}
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) vec.push_back(read());
	DFS(vec);
	for (int i=0;i<=7;i++) if (vis[i]) printf("%lld ",i);
	printf("\n");
	return 0;
}