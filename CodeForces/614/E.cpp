#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=30;

int n;
int a[maxn];

inline void imp(){
	printf("0\n");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++) putchar(i+'a'-1);
	}
	printf("\n");
}

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

signed main(){
	n=read();bool flg=false,no=false;
	for (int i=1;i<=n;i++){
		a[i]=read();
		if ((a[i]&1) && flg) no=true;
		if (a[i]&1) flg=true;
	}
	if (no){
		imp();
		return 0;
	}
	if (n==1){
		printf("%lld\n",a[1]);
		for (int i=1;i<=a[1];i++) putchar('a');
		printf("\n");
		return 0;
	}
	
	int g;
	g=a[1];
	for (int i=2;i<=n;i++) g=gcd(g,a[i]);
	if (!flg){
		printf("%lld\n",g);
		string otp1="",opt2="";
		for (int i=1;i<=n;i++){
			for (int j=1;j<=a[i]/g;j++) otp1+=(char)(i+'a'-1);
		}
		for (int i=n;i>=1;i--){
			for (int j=1;j<=a[i]/g;j++) opt2+=(char)(i+'a'-1);
		}
		for (int i=1;i<=g;i++) if (i&1) cout<<otp1; else cout<<opt2;
		printf("\n");
	} else {
		printf("%lld\n",g);
		string opt="";int mid;
		for (int i=1;i<=n;i++) if (a[i]&1) {mid=i;break;}
		for (int i=1;i<=n;i++) if (i!=mid){
			for (int j=1;j<=a[i]/g/2;j++) opt+=(char)(i+'a'-1);
		}
		for (int i=1;i<=a[mid]/g;i++) opt+=(char)(mid+'a'-1);
		for (int i=n;i>=1;i--) if (i!=mid){
			for (int j=1;j<=a[i]/g/2;j++) opt+=(char)(i+'a'-1);
		}
		for (int i=1;i<=g;i++) cout<<opt;
		printf("\n");
	}
	return 0;
}