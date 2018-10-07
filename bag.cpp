/*
 * XJOI CONTEST1004 T2 背包问题
 * 180922 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxt=105,maxn=55;
int n,x=0,y=0;
struct good{
	int x,y;
	bool used;
};
vector<good> a;
bool chosen[maxt];
int type[maxn],taste[maxn];
int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) type[i]=read();
	for (int i=1;i<=n;i++){
		taste[i]=read();
		if (taste[i]>=0){
			x+=1-chosen[type[i]];
			y+=taste[i];
			chosen[type[i]]=true;
		} else a.push_back((good){type[i],taste[i],false});
	}
	ans=x*y;
	for (int i=0;i<a.size();i++){
		int max_now=-(1<<30),k=-1;
		for (int j=0;j<a.size();j++) if ((!a[j].used)&&(!chosen[a[j].x])&&((x+1)*(y+a[j].y) > max_now)) max_now=(x+1)*(y+a[j].y),k=j;
		if (k==-1) break;
		a[k].used=true;
		chosen[a[k].x]=true;
		if ((x+1)*(y+a[k].y)>ans) x++,y+=a[k].y,ans=x*y; else break;
	}
	printf("%lld\n",ans);
	return 0;
}