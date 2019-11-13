#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e6+5;
const int tt=1e9+7;

int n,m;
list<int> que[maxn];

signed main(){
	freopen("problem2.in","r",stdin);
	freopen("problem2.out","w",stdout);

	n=read(),m=read();
	for (int i=1;i<=n;++i) que[i].push_back(0);

	while (m--){
		int opt=read();
		if (opt==1){
			int i=read(),x=read();
			int y=que[i].front();
			que[i].pop_front();
			que[i].push_front((y-x+tt)%tt);
			que[i].push_front(x);
		} else if (opt==2){
			int i=read();
			int x=que[i].front(); que[i].pop_front();
			int y=que[i].front(); que[i].pop_front();
			que[i].push_front((x+y)%tt);
			printf("%d\n",x);
		} else if (opt==3){
			int i=read(),x=read();
			int y=tt-que[i].back(); que[i].pop_back();
			que[i].push_back((x-y+tt)%tt);
			que[i].push_back((-x+tt)%tt);
		} else if (opt==4){
			int i=read();
			int x=que[i].back(); que[i].pop_back();
			int y=que[i].back(); que[i].pop_back();
			que[i].push_back((x+y)%tt);
			printf("%d\n",tt-x);
		} else if (opt==5){
			int i=read(),x=read();
			int y1=que[i].front(); que[i].pop_front();
			que[i].push_front((y1+x)%tt);
			int y2=que[i].back(); que[i].pop_back();
			que[i].push_back((y2-x+tt)%tt);
		} else {
			int i=read(),j=read();
			int x=que[i].back(); que[i].pop_back();
			int y=que[j].front(); que[j].pop_front();
			que[j].push_front((x+y)%tt);
			que[i].splice(que[i].end(),que[j]);
			que[j].push_back(0);
		}
	}
	return 0;
}