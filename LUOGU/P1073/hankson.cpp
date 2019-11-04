#include<bits/stdc++.h>

//#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int T,ans=0;
int a0,a1,b0,b1;

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

bool check(int x){
	if (gcd(x/a1,a0/a1) != 1) return false;
	if (gcd(b1/x,b1/b0) != 1) return false;
	return true;
}

signed main(){
	T=read();
	while (T--){
		a0=read(),a1=read(),b0=read(),b1=read();
		ans=0;
		
		int sq=sqrt(b1);
		for (int i=1;i<=sq;i++) if (b1%i==0){
			if (i%a1==0) ans+=check(i);
			if (b1/i==i) continue;
			if (b1/i%a1==0) ans+=check(b1/i);
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
