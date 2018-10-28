#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define CLEAR(_) memset(_,0,sizeof(_))
using namespace std;
const long long maxn=10005;
long long T,n,m,delta,flag=0;
long long a[maxn],now[maxn*3],s;
long long q[maxn];

bool vis[maxn];
vector <long long> circle[maxn];

inline void init(){
	CLEAR(vis);
	for (long long i=0;i<n;i++) circle[i].clear();
}

int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&s,&m,&delta);
		init();
		for (long long i=0;i<n;i++) scanf("%lld",&a[i]);
		long long cnt=0;
		for (long long i=0;i<n;i++) if (!vis[i]){
			cnt++;
			long long k=i;
			while (!vis[k]) vis[k]=1,circle[cnt].push_back(a[k]),k=(k+delta)%n;
		}
		long long ans=0;
		for (long long k=1;k<=cnt;k++){
			long long circle_len=circle[k].size(),sum=0;
			for (long long i=0;i<circle_len;i++){
				now[i]=now[i+circle_len]=now[i+circle_len*2]=circle[k][i];
				sum+=now[i];
			}
			for (long long i=1;i<3*circle_len;i++) now[i]+=now[i-1];
			long long tail=0,head=1,len=m%circle_len,h=m/circle_len;
			if (h>0) h--,len+=circle_len;
			long long now_ans=0;
			for (long long i=0;i<3*circle_len;i++){
				while (tail>=head&&now[i]<=now[q[tail]]) tail--;
				q[++tail]=i;
				while (i-q[head]>len) head++;
				if(head<=tail) now_ans=max(now_ans,now[i]-now[q[head]]);
			}
			if (sum>0) now_ans+=sum*h;
			ans=max(ans,now_ans);
		}
		printf("Case #%lld: %lld\n",++flag,max(s-ans,(long long)0));
	}
	return 0;
}