#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const long long maxn=2505;
long long n,ans=1,tt=1e9+7;
char s[maxn];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	long long cnt=0;
	for (long long i=n;i>=1;i--) if (s[i]==')'){
		cnt++;
	} else {
		ans=(ans*cnt)%tt;
		cnt--;
	}
	printf("%lld\n",ans);
	return 0;
}