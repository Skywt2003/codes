#include<bits/stdc++.h>
using namespace std;
 
string s, tmp, f[111];
int cnt=1, x=1, fa[111];
vector<int>G[111];
 
void con(int x,int y){
	G[x].push_back(y);
	fa[y]=x;
}
 
#define psi pair<string,int>
#define fi first
#define se second
 
void dfs(int x){
	string ans;
	vector<psi>vec;
	for (auto y:G[x])
		dfs(y), vec.push_back((psi){f[y],y});
	int las=0;
	sort(vec.begin(),vec.end());
	for (auto o:vec){
		if (o.se>las){
			las=o.se;
			ans=ans+o.fi;
		}
	}
	ans="("+ans+")";
	if (x==1) ans=vec.front().fi;
	f[x]=ans;
}

int main(){
	cin>>s;
	for (auto c:s){
		if (c=='('){
			++cnt;
			con(x,cnt);
			x=cnt;
		}else{
			x=fa[x];
		}
	}
	dfs(1);
	cout<<f[1]<<endl;
}