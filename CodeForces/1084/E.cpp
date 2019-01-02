#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=500005;
int n,k,now=0,ans=0;

string s,t;
int st=-1;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();k=read();
	cin>>s>>t;
	for (int i=0;i<n;i++) if (s[i]==t[i]) ans++; else {st=i;break;}
	if (st==-1){
		printf("%lld\n",ans);
		return 0;
	}
	now=1;
	for (int i=st;i<n;i++){
		int lst=now;
		now=now*2 - ('b'-t[i]) - (s[i]-'a');
		if (now>k){
			ans+=k*(n-i);
			break;
		} else ans+=now;
	}
	printf("%lld\n",ans);
	return 0;
}