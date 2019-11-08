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

int m,len;
char a[maxn];
int f[maxn][maxn];
int sum[maxn],tmp[maxn];

void add_mode(int &x,int y){
	x=(x+y)%tt;
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	scanf("%s",a+1); len=strlen(a+1);
	m=read();
	f[0][0]=1;tmp[0]++;
	for (int i=1;i<10;i++) f[1][i%m]++,tmp[i%m]++;
	for (int i=2;i<=len;i++){
		for (int j=0;j<m;j++) sum[j]=tmp[j];
		for (int j=0;j<m;j++){
			for (int w=1;w<=9;w++) add_mode(f[i][j],sum[(j-w%m+m)%m]);
			add_mode(tmp[j],f[i][j]);
		}
	}
	
	#ifdef DEBUG
		for (int i=1;i<=len;i++) printf("f[%lld][0] = %lld\n",i,f[i][0]);
	#endif
	
	int ans=0,presum=0;
	for (int i=1;i<len;i++) add_mode(ans,f[i][0]);
	for (int i=1;i<=len;i++){
		for (int j=i;j<=len;j++)
			for (int w=(i==1);w<a[i]-'0';w++)
				add_mode(ans,f[len-j][(m-presum-w%m+m)%m]%tt);
		presum=(presum+a[i]-'0')%m;
	}
	add_mode(ans,presum==0);
	
	printf("%lld\n",ans);
	return 0;
}
