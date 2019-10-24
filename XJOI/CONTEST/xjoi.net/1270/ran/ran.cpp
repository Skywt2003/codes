#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=10005;

int n,q,opt,last_ans=0;

int f[maxn*4];

#define ls (p<<1)
#define rs (p<<1|1)
#define fa (p>>1)
#define mid (((tr-tl)>>1)+tl)

int query(int sl,int sr,int tl,int tr,int p){
	if (tr<sl || sr<tl) return 0;
	if (tl==tr){
		#ifdef DEBUG
			printf("sl=%lld sr=%lld [%lld,%lld] ret=%lld\n",sl,sr,tl,tr,(sr-sl+1)-f[fa]);
		#endif
		// return (sr-sl+1)-f[fa];
		return max(1ll,tl-sl+1)*max(1ll,sr-tr+1)-f[fa];
	}

	f[p]=f[fa]+(sl<=tl && tr<=sr);
	int ret=0;
	if (tl<=sl && sr<=tr) ret=(sr-sl+1)*(sr-sl+2)/2; else
	ret=max(1ll,tl-sl+1)*max(1ll,sr-tr+1);
	if (sl<=mid  ) ret+=query(sl,sr,tl,mid,ls);
	if (mid+1<=sr) ret+=query(sl,sr,mid+1,tr,rs);
	#ifdef DEBUG
		printf("sl=%lld sr=%lld [%lld,%lld] ret=%lld f=%lld\n",sl,sr,tl,tr,ret,f[p]);
	#endif
	return ret;
}

#undef ls
#undef rs
#undef fa
#undef mid

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); q=read(); opt=read();
	while (q--){
		int a=read(),b=read();
		int l=(a^(last_ans*opt))%n+1;
		int r=(b^(last_ans*opt))%n+1;
		if (l>r) swap(l,r);
		f[1]=(l==1&&r==n);
		printf("%lld\n",last_ans=query(l,r,1,n,1));
	}
	return 0;
}