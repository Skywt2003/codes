#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn=1005;

#define int long long

int n,k;
char s[maxn];
int w[maxn];
int maxnum=-1;

signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%lld",&k);
	for (int i=0;i<26;i++){
		scanf("%lld",&w[i]);
		maxnum=max(maxnum,w[i]);
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans+=i*w[s[i]-'a'];
	for (int i=n+1;i<=n+k;i++) ans+=i*maxnum;
	cout<<ans<<endl;
	return 0;
}