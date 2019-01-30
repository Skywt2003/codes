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

const int maxn=105;

int k,n;
char s[maxn];
bool vis[30];
int cnt=0;

inline bool check(){
	int ret=0;
	for (int i=1;i<=n;i++) if (!vis[s[i]-'a']) vis[s[i]-'a']=true,ret++;
	memset(vis,0,sizeof(vis));
	return ret>=k;
}

signed main(){
	k=read();
	scanf("%s",s+1);
	n=strlen(s+1);
	if (!check()){
		printf("NO\n");
		return 0;
	}
	cout<<"YES"<<endl;
	bool is1=true;
	for (int i=1;i<=n;i++){
		if (!vis[s[i]-'a'] && cnt<k){
			if (!is1) cout<<endl;
			cnt++;vis[s[i]-'a']=true;is1=false;
		}
		putchar(s[i]);
	}
	return 0;
}