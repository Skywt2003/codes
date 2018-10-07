/*
 * XJOI CONTEST1001 T2 天天删括号
 * 180921 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl

const int maxn=105;
int n,match[maxn];
string s;
stack <int> stk;

inline void build_match(){
	n=s.length();
	for (int i=0;i<n;i++) if (s[i]=='(') stk.push(i); else match[stk.top()]=i,stk.pop();
}

inline string get_answer(int L,int R){
	vector<string> res;res.clear();
	for (int i=L+1;i<=R-1;i=match[i]+1) if (s[i]=='('){
		string now=get_answer(i,match[i]);
		while (!res.empty()&&now<res.back()) res.pop_back();
		res.push_back(now);
	}
	string ret="(";
	for (int i=0;i<res.size();i++) ret=ret+res[i];
	return ret+")";
}

int main(){
	cin>>s;
	build_match();
	string ans="";
	for (int i=0;i<100;i++) ans=ans+')';
	for (int i=0;i<n;i=match[i]+1) ans=min(ans,get_answer(i,match[i]));
	cout<<ans<<endl;
	return 0;
}