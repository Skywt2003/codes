#include<bits/stdc++.h>

#define int long long

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e7+5;

int T,n,k;
char a[maxn];
int f[maxn];

int que[maxn];
int head=1,tail=0;

void init(){
	memset(f,0x3f,sizeof(f));
	memset(que,0,sizeof(que));
	head=1,tail=0;
}

signed main(){
	T=read();
	while (T--){
		init();

		n=read(),k=read();
		scanf("%s",a+1);

		for (int i=-k;i<=n;i++){
			if (i>0){
				f[i]=f[i-1]+i;
				while (head<=tail && i-que[head] > 2*k+1) head++;
				if (head<=tail) f[i]=min(f[i],f[que[head]]+min(que[head]+k+1,n));
			} else if (i==0) f[i]=0;

			if (a[min(i+k+1,n)]=='1'){
				int now=(i>=0?f[i]:0)+min(i+k+1,n);
				while (head<=tail && now <= f[que[tail]]) tail--;
				que[++tail]=i;
			}
		}

		#ifdef DEBUG
			for (int i=0;i<=n;i++) printf("f[%lld] = %lld\n",i,f[i]);
		#endif

		printf("%lld\n",f[n]);
	}
	return 0;
}