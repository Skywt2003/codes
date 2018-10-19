#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
#define int long long

const int maxlen=1e5+5;
int T;
int len1,len2;
char s[maxlen],t[maxlen];

inline bool check(int x){
	for (int i=0;i<len2;i++) if (x+i>=len1 || s[x+i]!=t[i]) return false;
	return true;
}

signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%s%s",s,t);
		len1=strlen(s);
		len2=strlen(t);
		if (len1==len2&&check(0)) {printf("pty\n");continue;}
		bool ans;
		if ((len1-len2)&1) ans=check((len1-len2)/2)&&check((len1-len2)/2+1);
		else ans=check((len1-len2)/2)||(check((len1-len2)/2-1)&&check((len1-len2)/2+1));
		if (ans) printf("pty\n"); else printf("cqf\n");
	}
	return 0;
}