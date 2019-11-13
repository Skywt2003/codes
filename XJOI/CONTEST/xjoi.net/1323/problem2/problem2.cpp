#pragma GCC optimize(2)

#include<bits/stdc++.h>

//#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
const int tt=1e9+7;

int n,m;
deque<int> que[maxn];
int delta[maxn];

signed main(){
	freopen("problem2.in","r",stdin);
	freopen("problem2.out","w",stdout);
	n=read();m=read();
	while (m--){
		int opt=read();
		if (opt==1){
			int i=read(),x=read();
			que[i].push_front((x-delta[i]+tt)%tt);
		} else if (opt==2){
			int i=read();
			printf("%d\n",(que[i].front()+delta[i])%tt);
			que[i].pop_front();
		} else if (opt==3){
			int i=read(),x=read();
			que[i].push_back((x-delta[i]+tt)%tt);
		} else if (opt==4){
			int i=read();
			printf("%d\n",(que[i].back()+delta[i])%tt);
			que[i].pop_back();
		} else if (opt==5){
			int i=read(),d=read();
			delta[i]=(delta[i]+d)%tt;
		} else if (opt==6){
			int i=read(),j=read();
			if (que[i].size() >= que[j].size()){
				while (!que[j].empty())
					que[i].push_back((que[j].front()+delta[j]-delta[i]+tt)%tt),
					que[j].pop_front();
			} else {
				while (!que[i].empty())
					que[j].push_front((que[i].back()+delta[i]-delta[j]+tt)%tt),
					que[i].pop_back();
				que[i]=que[j]; delta[i]=delta[j];
				que[j].clear(); delta[j]=0;
			}
		}
	}
	return 0;
}
