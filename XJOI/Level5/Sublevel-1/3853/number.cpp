#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=17+5,maxm=50+5;
int n,m,len[maxm];
string num[maxm];
bool vis[maxm];
vector<string> s;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void delete_number(){
	memset(vis,true,sizeof(vis));
	for (int i=1;i<=m;i++)
	for (int j=1;j<=m;j++) if (i!=j&&vis[i]==true&&vis[j]==true){
		if (len[i]<len[j]){
			string now=num[j].substr(0,len[i]);
			if (now==num[i]) vis[j]=false;
		} else if (len[i]>len[j]){
			string now=num[i].substr(0,len[j]);
			if (now==num[j]) vis[i]=false;
		} else if (len[i]==len[j]){
			if (num[i]==num[j]) vis[i]=false;
		}
	}
	for (int i=1;i<=m;i++) if (vis[i]) s.push_back(num[i]);
}

inline int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret*=w;
		w=w*w;b>>=1;
	}
	return ret;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++) cin>>num[i],len[i]=num[i].length();
	delete_number();
	int total=qsm(10,n);
	for (int i=0;i<s.size();i++){
		int now=s[i].length();
		total-=qsm(10,n-now);
	}
	printf("%lld\n",total);
	return 0;
}