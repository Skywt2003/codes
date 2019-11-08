#include<bits/stdc++.h>

#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;
const int tt=123456789;

int n,m;

int ans=0;

int count(int x){
	int ret=0;
	while (x){
		ret=(ret+x%10%m)%m;
		x/=10;
	}
	return ret;
}

int get_len(int x){
	int ret=0;
	while (x) ret++,x/=10;
	return ret;
}

int f[maxn][maxn];

int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w;
		b>>=1; w=w*w;
	}
	return ret;
}


signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read();m=read();
	
	int len=get_len(n);
	for (int i=1;i<=qsm(10,len);i++) ans+=(i<=n)&&(count(i)==0),f[get_len(i)][count(i)]++;
	
	#ifdef DEBUG
		for (int i=1;i<=get_len(n);i++) printf("f[%lld][0] = %lld\n",i,f[i][0]);
	#endif
	
	printf("%lld\n",ans);
	
	return 0;
}
