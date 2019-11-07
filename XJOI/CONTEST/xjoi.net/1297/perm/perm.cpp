#include<bits/stdc++.h>

//#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=1e9+7;

const int maxn=25; // Only for subtask #1 (10pts...)

int n,m,a[maxn],alls;
int ans=0;

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		b>>=1; w=w*w%tt;
	}
	return ret;
}

signed main(){
	n=read(); m=read(); alls=1<<n;
	for (int i=0;i<n;i++) a[i]=read();
	
	for (int i=1;i<alls;i++){
		int now=0,num=0;
		for (int j=0;j<n;j++) if ((i&(1<<j)) && a[j]>num) num=a[j],now++;
		ans=(ans+qsm(now,m))%tt;
	}
	printf("%d\n",ans);
	return 0;
}
