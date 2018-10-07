/*
 * XJOI CONTEST1001 T2 天天删括号
 * 180920 By SkyWT
 * This is a FAKE code that can't AC...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

const int maxn=105;
char s[maxn];
int n;
bool vis[maxn];

struct del_info{
	int k;
	string s;
};
vector <del_info> vec;

inline bool compare(del_info aa,del_info bb){
	return aa.s<bb.s;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) if (s[i]==')'){
		string std_now="";
		for (int j=1;j<=n;j++) if (!vis[j]) std_now+=s[j];
		vec.clear();
		for (int j=i+1;j<=n;j++) if ((!vis[j])&&(s[j]=='(')){
			string now="";
			for (int k=1;k<=n;k++) if (k!=i&&k!=j) now+=s[k];
			vec.push_back((del_info){j,now});
		}
		sort(vec.begin(),vec.end(),compare);
		if (vec.size()==0) continue;
		if (vec[0].s>=std_now) continue;
		vis[i]=vis[vec[0].k]=true;
	}
	for (int i=1;i<=n;i++) if (!vis[i]) putchar(s[i]);
	printf("\n");
	return 0;
}