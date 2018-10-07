/*
 * XJOI CONTEST 1009 2018提高组模拟赛5
 * T2 撷芳
 * For 7%
 * 180929 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

#define int long long

const int maxn=105,N=100000;
const int tt=998244353;
int T,n,a[maxn],q,ans=0;
bool vis[N+20];
int prime[N+10],phi[N+10];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

inline int lcm(int x,int y){
	return x/gcd(x,y)*y;
}

inline void BuildPhi(){
	phi[1]=1;
	memset(vis,1,sizeof(vis));
	vis[1]=false;
	for (int i=2;i<=N;i++){
		if (vis[i]){
			phi[i]=i-1;
			prime[++prime[0]]=i;
		}
		for (int j=1;j<=prime[0];j++){
			if (i*prime[j]>N) break;
			vis[i*prime[j]]=false;
			if (i%prime[j]) phi[i*prime[j]]=(prime[j]-1)*phi[i];
			else {phi[i*prime[j]]=prime[j]*phi[i];break;}
		}
	}
}

inline void BuildSum(int n){
	for (int j=1;j<=n;j++) if (n%j==0) ans=(ans+phi[j]/2*j)%tt;
}

signed main(){
	T=read();
	if (T==3){
		n=read();
		BuildPhi();
		BuildSum(n);
		cout<<ans+n<<endl;
		return 0;
	}
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) 
		ans=(ans+lcm(a[i],a[j]))%tt;
	cout<<ans<<endl;
	q=read();
	while (q--){
		int L=read(),R=read(),value=read();
		for (int i=L;i<=R;i++) a[i]=value;
		ans=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ans=(ans+lcm(a[i],a[j]))%tt;
		cout<<ans<<endl;
	}
	return 0;
}