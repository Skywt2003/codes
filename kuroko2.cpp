/*
 * XJOI CONTEST1005 T1 白井黑子 (Kuroko)
 * 180925 By SkyWT
 *
 * 别看了，码风清奇……
 */

#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

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

int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;
int n,k,ans=0;
int x[maxn],f[maxn];
struct num{
	int numa,numb,numc,numd;
	bool flag;
	void clear(){
		numa=numb=numc=numd=0;flag=false;
	}
	bool operator <(num b)const{
		if (numa==b.numa&&numb==b.numb&&numc==b.numc&&numd==b.numd) return flag<b.flag; else
		if (numa==b.numa&&numb==b.numb&&numc==b.numc) return numd<b.numd; else
		if (numa==b.numa&&numb==b.numb) return numc<b.numc; else
		if (numa==b.numa) return numb<b.numb; else
		return numa<b.numa;
	}
	bool iszero(){
		if (numa||numb||numc||numd||flag) return false;
		return true;
	}
};
vector<num> a;
map<num,int> mp;

inline int get_number(int x){
	int ret=1;
	while (x) ret=ret*(x%10),x/=10;
	return ret;
}

signed main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) x[i]=read();
	sort(x+1,x+1+n);
	for (int i=1;i<=n;i++) f[i]=get_number(x[i]);
	if (k==0){
		int cnt=0;
		for (int i=1;i<=n;i++) cnt+=(f[i]==1);
		printf("%lld\n",n*(n-1)/2-cnt*(cnt-1)/2);
		return 0;
	}
	for (int i=1;i<=n;i++){
		num now;now.clear();
		int xx=f[i];
		if (xx==0) {a.push_back(now);continue;}
		now.flag=true;
		while ((xx%2==0)) now.numa++,xx/=2;
		while ((xx%3==0)) now.numb++,xx/=3;
		while ((xx%5==0)) now.numc++,xx/=5;
		while ((xx%7==0)) now.numd++,xx/=7;
		now.numa%=k;
		now.numb%=k;
		now.numc%=k;
		now.numd%=k;
		a.push_back(now);
	}
	
	ans=n*(n-1)/2;
	for (int i=0;i<n;i++){
		if (a[i].iszero()) ans-=i; else
		ans-=mp[(num){a[i].numa?(k-a[i].numa):0,
					  a[i].numb?(k-a[i].numb):0,
					  a[i].numc?(k-a[i].numc):0,
					  a[i].numd?(k-a[i].numd):0,true}]+mp[(num){0,0,0,0,false}];
		mp[a[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}