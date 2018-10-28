#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#define CLEAR(_) memset(_,0,sizeof(_))
using namespace std;
const int maxn=1005,maxnum=10005;
int n,q;
vector <int> a[maxnum];
bool vis[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int now=read();
		for (int j=1;j<=now;j++){
			int x=read();
			a[x].push_back(i);
		}
	}
	q=read();
	for (int i=1;i<=q;i++){
		CLEAR(vis);
		int x=read(),y=read();
		for (int i=0;i<a[x].size();i++) vis[a[x][i]]=true;
		bool flag=true;
		for (int i=0;i<a[y].size();i++) if (vis[a[y][i]]){
			printf("Yes\n");
			flag=false;
			break;
		}
		if (flag) printf("No\n");
	}
	return 0;
}