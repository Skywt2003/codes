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

const int maxn=105,maxe=100*100+5;
int n;
char s[maxn][maxn];

int tot=0,lnk[maxn],nxt[maxe],son[maxe],f[maxn],ord[maxn];
string ans="";

inline void add_edge(int x,int y){
	tot++;son[tot]=y;f[y]++;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

queue<int> que;

inline void Topology(){
	while (!que.empty()) que.pop();
	for (int i=1;i<=26;i++) if (f[i]==0) que.push(i),ord[i]=1,ans=ans+(char)('a'+i-1);
	while (!que.empty()){
		int head=que.front();que.pop();
		for (int i=lnk[head];i;i=nxt[i]){
			ord[son[i]]=max(ord[son[i]],ord[head]+1);
			f[son[i]]--;
			if (f[son[i]]==0) que.push(son[i]),ans=ans+(char)('a'+son[i]-1);
		}
	}
	for (int i=1;i<=26;i++) if (ord[i]==0){
		printf("Impossible\n");
		return;
	}
	cout<<ans<<endl;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			int len=min(strlen(s[i]+1),strlen(s[j]+1));
			bool fd=false;
			for (int k=1;k<=len;k++) if (s[i][k]!=s[j][k]){
				add_edge(s[i][k]-'a'+1,s[j][k]-'a'+1);fd=true;
				break;
			}
			if (!fd){
				if (strlen(s[j]+1)<strlen(s[i]+1)){
					printf("Impossible\n");
					return 0;
				}
			}
		}
	}
	Topology();
	return 0;
}