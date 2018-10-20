#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

#define int long long
using namespace std;

const int maxlen=25,maxn=10;
string a,b;
string from[maxn],to[maxn];
int n=1,len[maxn];
map<string,bool> vis;

inline int BFS(){
	queue<string> que;
	queue<int> step;
	while (!que.empty()) que.pop();
	while (!step.empty()) step.pop();
	vis[a]=true;
	que.push(a);step.push(0);
	while (!que.empty()){
		string now=que.front();que.pop();
		int ns=step.front();step.pop();
		int lennow=now.length();
		if (ns+1>10) continue;
		for (int i=1;i<=n;i++){
			for (int j=0;j<lennow-len[i]+1;j++) if (now.substr(j,len[i])==from[i]){
				string nxt=now;
				nxt.replace(j,len[i],to[i]);
				if (nxt==b) return ns+1;
				if (vis[nxt]) continue;
				vis[nxt]=true;
				que.push(nxt);
				step.push(ns+1);
			}
		}
	}
	return -1;
}

signed main(){
	cin>>a>>b;
	if (a==b){
		printf("0\n");
		return 0;
	}
	while (cin>>from[n]>>to[n]) len[n]=from[n].length(),n++;n--;
	int ans=BFS();
	if (ans==-1) printf("NO ANSWER!\n"); else printf("%lld\n",ans);
	return 0;
}