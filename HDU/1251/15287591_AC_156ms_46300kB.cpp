#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
const int maxn=100005;
int t[10*maxn][30],sum[10*maxn],tot=0;
char sr[15];

inline void insert(char s[]){
	int p=0,len=strlen(s);sum[p]++;
	for (int i=0;i<len;i++){
		int now=s[i]-'a';
		if (!t[p][now]) t[p][now]=++tot;
		p=t[p][now];sum[p]++;
	}
}
inline int query(char s[]){
	int p=0,len=strlen(s);
	for (int i=0;i<len;i++){
		int now=s[i]-'a';
		if (!t[p][now]) return 0;
		p=t[p][now];
	}
	return sum[p];
}

int main(){
	while (gets(sr)){
		if (strlen(sr)==0) break;
		insert(sr);
	}
	while (gets(sr)){
		if (strlen(sr)==0) break;
		printf("%d\n",query(sr));
	}
	return 0;
}