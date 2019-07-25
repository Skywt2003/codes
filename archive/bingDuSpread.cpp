#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=1000005,maxlen=55,maxlen_q=1000005;
int T,n,cnt=0;
int c[maxn][30],fail[maxn],val[maxn];
char s[maxlen],q[maxlen_q];
queue<int> que;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

void insert(char s[]){ // Insert a word to Trie Tree
	int len=strlen(s),x=0;
	for (int i=0;i<len;i++){
		int now=s[i]-'a';
		if (!c[x][now]) c[x][now]=++cnt;
		x=c[x][now];
	}
	val[x]++;
}

void buildFail(){ // Build Mismatch Pointer
	for (int i=0;i<26;i++) if (c[0][i]) que.push(c[0][i]);
	while (!que.empty()){
		int x=que.front();que.pop();
		for (int i=0;i<26;i++) if (c[x][i]){
			fail[c[x][i]]=c[fail[x]][i];
			que.push(c[x][i]);
		} else c[x][i]=c[fail[x]][i];
	}
}

int query(char s[]){
	int len=strlen(s),ret=0,x=0;
	for (int i=0;i<len;i++){
		int now=s[i]-'a';
		x=c[x][now];
		for (int t=x;t&&~val[t];t=fail[t]) ret+=val[t],val[t]=-1;
	}
	return ret;
}

int main(){
	
	return 0;
}