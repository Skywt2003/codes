#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
char a[maxn];
int n;
int num[maxn],lst[maxn];
string ans;

signed main(){
	scanf("%s",a+1);n=strlen(a+1);
	for (char ch='a';ch<='z';ch++){
		for (int i=1;i<=n;i++) if (a[i]==ch) num[ch-'a']++,lst[ch-'a']=i;
	}
	int now_lst=0;ans="";
	for (int ch='z';ch>='a';ch--){
		if (num[ch-'a']==0) continue;
		if (lst[ch-'a']<now_lst) continue;
		for (int i=now_lst;i<=lst[ch-'a'];i++) if (a[i]==ch) ans+=ch;
		now_lst=lst[ch-'a'];
	}
	cout<<ans<<endl;
	return 0;
}