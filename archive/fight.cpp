/*
 * XJOI CONTEST1004 T1 战斗吧，少年
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

const int maxn=55,maxm=55;
int n,a[maxn];
int m,sum=0;
struct enermy{
	int b,c;
};
enermy b[maxm];
int ans=-1;

inline bool check(int x){
	// printf("Check %d now.\n",x);
	int j=1,left_enermy=b[1].c;
	for (int i=1;i<=n;i++){
		if (a[i]<b[j].b) return false;
		int nowx=x;
		while (left_enermy<=nowx && a[i]>=b[j].b){
			nowx-=left_enermy;
			j++;left_enermy=b[j].c;
			if (j>m||j==m&&left_enermy==0) return true;
		}
		if (a[i]>=b[j].b) left_enermy-=nowx; else return false;
		while (left_enermy==0 && j+1<=m) j++,left_enermy=b[j].c;
		if (j>m||j==m&&left_enermy==0) return true;
	}
	if (j>m||(j==m && left_enermy==0)) return true;
	return false;
}

inline bool compare_a(int a,int b){
	return a>b;
}

inline bool compare_b(enermy aa,enermy bb){
	return aa.b>bb.b;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	m=read();
	for (int i=1;i<=m;i++) b[i].b=read();
	for (int i=1;i<=m;i++){
		b[i].c=read();
		if (b[i].c<0) b[i].c=0;
		sum+=b[i].c;
	}

	sort(a+1,a+1+n,compare_a);
	sort(b+1,b+1+m,compare_b);
	if (a[1]<b[1].b) {printf("-1\n");return 0;}

	int L=1,R=sum;
	while (L<=R){
		int mid=((R-L)>>1)+L;
		if (check(mid)) ans=mid,R=mid-1; else L=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}