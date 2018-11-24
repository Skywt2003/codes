#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn=100005;
const int INF=1e9+10;
int n,m,p[maxn];
pair<int,int> road[maxn];
int A,X,B,Y;
bool need[maxn];
int ans=1e9+10;
int f[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline char read_char(){
	char ch=getchar();
	while (ch!='A'&&ch!='B'&&ch!='C') ch=getchar();
	return ch;
}

inline bool check(){
	for (int i=1;i<n;i++) if (need[road[i].first]==false && need[road[i].second]==false) return false;
	return true;
}

inline void build(int step,int sum){
	if (sum>ans) return;
	if (step==n){
		if (!check()) return;
		ans=min(ans,sum);
		return;
	}
	if (step+1==A){
		need[step+1]=X;
		build(step+1,sum+X*p[step+1]);
	} else if (step+1==B){
		need[step+1]=Y;
		build(step+1,sum+Y*p[step+1]);
	} else {
		need[step+1]=1;
		build(step+1,sum+p[step+1]);
		need[step+1]=0;
		build(step+1,sum);
	}
}

int main(){
	n=read();m=read();
	char opt=read_char();int xx=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		road[i]=make_pair(x,y);
	}
	for (int i=1;i<=m;i++){
		A=read(),X=read(),B=read(),Y=read();
		if (opt=='A'){
			if ((B==A+1 || A==B+1)&&(X==0 && Y==0)){
				printf("-1\n");
				continue;
			}
			memset(f,0x3f,sizeof(f));
			int INF=f[0];
			if ((A==1 && X==0) || (B==1 && Y==0)) f[1]=INF; else f[1]=p[1];
			if ((A==2 && X==0) || (B==2 && Y==0)) f[2]=INF; else {
				if ((A==1 && X==1) || (B==1 && Y==1)) f[2]=p[2]+p[1]; else f[2]=p[2];
			}
			for (int i=3;i<=n;i++){
				if ((i==A && X==0) || (i==B && Y==0)) continue; else
				if ((i-1==A && X==1) || (i-1==B && Y==1)) f[i]=f[i-1]+p[i]; else
				if ((i-1==A && X==0) || (i-1==B && Y==0) || (i-2==A && X==1) || (i-2==B && Y==1)) f[i]=f[i-2]+p[i];
				else f[i]=min(f[i-1]+p[i],f[i-2]+p[i]);
				if (f[i]>INF) f[i]=INF;
			}
			int ans=INF;
			if ((n==A && X==0) || (n==B && Y==0) || (n-1==A && X==1) || (n-1==B && Y==1)) ans=f[n-1]; else
			if ((n==A && X==1) || (n==B && Y==1)) ans=f[n]; else ans=min(f[n],f[n-1]);
			if (ans==INF) printf("%d\n",-1); else printf("%d\n",ans);
		} else {
			ans=1e9+10;
			build(0,0);
			printf("%d\n",((ans==1e9+10)?(-1):ans));
		}
	}
	return 0;
}
