/*
 * XJOI CONTEST1001 T2 天天删括号
 * 180920 By SkyWT
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
string s;
int n,len;

struct del_info{
	int k;
	string s;
};
vector <del_info> vec;

inline bool compare(del_info aa,del_info bb){
	return aa.s<bb.s;
}

int main(){
	cin>>s;
	len=n=s.length();
	while (len>2){
		vec.clear();
		for (int i=0;i<len;i++) if ((s[i]=='(')&&(s[i+1]==')')){
			string now="";
			for (int j=0;j<len;j++) if (j!=i&&j!=i+1) now+=s[j];
			vec.push_back((del_info){i,now});
		}
		sort(vec.begin(),vec.end(),compare);
		if (vec.size()==0) break;
		if (vec[0].s>=s) break;
		s=vec[0].s;
		len=s.length();
	}
	cout<<s<<endl;
	return 0;
}