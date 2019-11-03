#include<bits/stdc++.h>
#define int long long

using namespace std;

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=300005;

int n;
char s[maxn];
int a[maxn],tmp[maxn];
int sum[maxn];

int stk[maxn],stk_top=0,l[maxn],r[maxn];
int cnt[maxn],deep[maxn];

int ans=0,ans1=1,ans2=1;

void fix_answer(int x,int id){
	if (x<ans) return;
	ans=x; ans1=l[id]; ans2=r[id];
}

signed main(){
	n=read();
	scanf("%s",s+1);
	int minnum=INF,k=-1;

	for (int i=1;i<=n;i++){
		a[i]=tmp[i]=(s[i]=='(')?1:-1,sum[i]=sum[i-1]+a[i];
		if (sum[i]<minnum) minnum=sum[i],k=i;
	}
	if (sum[n]!=0) return printf("0\n1 1\n"),0;

	for (int i=1;i<=k;i++) a[i+(n-k)]=tmp[i];
	for (int i=k+1;i<=n;i++) a[i-k]=tmp[i];

	int tot=0;
	for (int i=1;i<=n;i++){
		if (a[i]==1) cnt[stk[stk_top]]++,stk[++stk_top]=++tot,deep[tot]=stk_top,l[tot]=i;
		else r[stk[stk_top]]=i,stk_top--;
	}

	ans=cnt[0];
	for (int i=1;i<=tot;i++)
		if (deep[i]==1) fix_answer(cnt[i]+1,i); else
		if (deep[i]==2) fix_answer(cnt[0]+cnt[i]+1,i);

	printf("%lld\n%lld %lld\n",ans,(ans1+k-1)%n+1,(ans2+k-1)%n+1);
	return 0;
}