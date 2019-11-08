#include<bits/stdc++.h>

#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=305;

int n;
double h[maxn];

int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) h[i]=read();
	
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			bool flg=true;
			double delta=(h[i]<h[j])?((h[j]-h[i])/(j-i)):((h[i]-h[j])/(j-i));
			for (int k=i+1;k<j;k++) if (h[k] >= (((h[i]<h[j])?(delta*(k-i)+h[i]):(delta*(j-k)+h[j])))){flg=false; break;}
			ans+=flg;
		}
		
	printf("%lld\n",ans);
	return 0;
}
