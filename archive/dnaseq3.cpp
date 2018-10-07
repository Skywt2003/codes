/*
 * Vjudge CONTEST 239393
 * LightOJ 1073
 * H - DNA Sequence
 * 181004 By SkyWT
 */


#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=16,maxs=32768+2;
int T,n,alls,len[maxn];
string s[maxn];
string forp[maxn][maxn];
bool use[maxn];
vector <string> vec;
vector <int> vlen;
int f[maxs],delta[maxs],toadd[maxs];

inline bool inc(string a,string b){ // 返回串 a 是否包含于 b 中
	int len1=a.length(),len2=b.length();
	if (len1>len2) return false;
	for (int i=0;i<len2 && i+len1<=len2;i++){
		bool flag=true;
		for (int j=i;j<i+len1;j++) if (a[j-i]!=b[j]) {flag=false;break;}
		// if (flag) cout<<a<<" in "<<b<<endl;
		if (flag) return true;
	}
	// cout<<a<<" not in "<<b<<endl;
	return false;
}

inline void make_p(){
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++) if (i!=j){
		bool aflag=false;
		for (int k=max(vlen[i]-vlen[j],(long long)0);k<vlen[i];k++){
			bool flag=true;
			for (int t=k;t<k+vlen[j] && t<vlen[i];t++) if (vec[i][t]!=vec[j][t-k]){flag=false;break;};
			if (flag){
				forp[i][j]="";
				for (int t=vlen[i];t<k+vlen[j];t++) forp[i][j]+=vec[j][t-k];
				aflag=true;break;
			}
		}
		if (!aflag) forp[i][j]=vec[j];
		// cout<<vec[i]<<" --> "<<vec[j]<<" forp="<<forp[i][j]<<endl;
	}
}

inline void get_answer(int now,int lst){
	if (now>=alls-1) return;
	if (lst==-1) cout<<vec[toadd[now]]; else cout<<forp[lst][delta[now]];
	get_answer(now+toadd[now],delta[now]);
}

signed main(){
	// cout<<(int)sizeof(f[0])<<endl;
	T=read();
	for (int cnt=1;cnt<=T;cnt++){
		n=read();
		for (int i=0;i<n;i++){
			cin>>s[i];
			len[i]=s[i].length();
		}
		memset_clear_tre(use);
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) if (i!=j){
			if (inc(s[i],s[j])) use[i]=false;
		}
		vec.clear();vlen.clear();
		for (int i=0;i<n;i++) if (use[i]) vec.push_back(s[i]),vlen.push_back(len[i]);
		// sort(vec.begin(),vec.end());
		n=vec.size();alls=1<<n;

		make_p();

		memset_clear_max(f);
		f[alls-1]=0;
		memset_clear_reg(delta);
		for (int i=alls-1;i>0;i--)
			for (int j=0;j<n;j++) if ((i&(1<<j))){
				int lst=i-(1<<j);
				if (delta[lst]==-1 || f[i]+forp[delta[lst]][j].length() < f[lst]) f[lst]=f[i]+forp[delta[i]][j].length(),delta[lst]=j,toadd[lst]=j;
				else if (f[i]+forp[delta[lst]][j].length() == f[lst]){
					if (forp[delta[lst]][j] < forp[delta[lst]][delta[i]]) f[lst]=f[i]+forp[delta[lst]][j].length(),delta[lst]=j,toadd[lst]=j;
				}
			}

		get_answer(0,-1);
	}
	return 0;
}