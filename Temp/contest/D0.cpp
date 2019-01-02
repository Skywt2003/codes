#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;
int n;
bool vis[maxn];
vector<int> s;

inline void DFS(int now,vector<int> v){
	if (now==n){
		for (int i=0;i<(int)v.size();i++) s.push_back(v[i]);
		return;
	}
	vector<int> nxt;
	for (int i=1;i<=n;i++) if (!vis[i]){
		vis[i]=true;
		nxt=v;nxt.push_back(i);
		DFS(now+1,nxt);
		vis[i]=false;
	}
}

signed main(){
	n=read();
	vector<int> st;st.clear();
	DFS(0,st);
	int sum=(1+n)*n/2;
	int now=0;
	for (int i=0;i<n;i++) now+=s[i];
	int ans=0;
	for (int i=0;i<(int)s.size()-n+1;i++){
		if (now==sum) ans++;
		cout<<now<<" ";
		if (i<s.size()-n) now=now-s[i]+s[i+n];
	}
	cout<<endl;
	printf("%lld\n",ans);
	return 0;
}