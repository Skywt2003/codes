/*
 * Vjudge CONTEST 239393
 * LightOJ 1073
 * H - DNA Sequence
 * 181003 By SkyWT
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

const int maxn=17,maxs=32768+10,tt=19260817;
int T,n,alls,len[maxn];
string s[maxn],f[maxs][maxn];
string forp[maxn][maxn];
bool use[maxn];
vector <string> vec;
vector <int> vlen;
int inv;

inline int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt;b>>=1;
	}
	return ret;
}

inline int get_number(string s){
	int ret=0,len=s.length();
	for (int i=0;i<len;i++) ret=(ret*31%tt+(s[i]-'A'+1))%tt;
	// printf("number: %lld\n",ret);
	return ret;
}

inline string get_string(int number){
	string ret="";
	number%=tt;
	// int cnt=0;
	while (number){
		// if (++cnt<=10) putchar('A'+number%31),printf("\nnumber=%lld\n",number);
		printf("%lld\n", number% 31);
		ret+=('A'+number%31);
		number=number*inv%tt;
		printf("NUM=%lld\n",number);
		if (ret.size() > 6) break;
	}
	return ret;
}

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

inline void init(){
	for (int i=1;i<alls;i++)
	for (int j=0;j<n;j++)
		f[i][j]="@";
}

signed main(){
	inv=qsm(31,tt-2);
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

		init();
		for (int i=0;i<n;i++) f[1<<i][i]=vec[i];
		for (int i=1;i<alls;i++)
		for (int k=0;k<n;k++) if (i&(1<<k)){
			for (int j=0;j<n;j++) if (!(i&(1<<j))){
				string now=f[i][k];
				if (now=="@") continue;
				now=now+forp[k][j];
				if (f[i+(1<<j)][j]=="@") f[i+(1<<j)][j]=now; else {
					int len1=now.length(),len2=f[i+(1<<j)][j].length();
					if (len1>len2) continue;
					else if (len1<len2) f[i+(1<<j)][j]=now;
					else f[i+(1<<j)][j]=min(f[i+(1<<j)][j],now);
				}
			}
		}
		string ans="@";
		int ans_len=-1;
		for (int i=0;i<n;i++) if (f[alls-1][i]!="@"){
			int len_now=f[alls-1][i].length();
			if (ans_len==-1){
				ans=f[alls-1][i],ans_len=len_now;
				continue;
			}
			if (len_now>ans_len) continue; else
			if (len_now<ans_len) ans=f[alls-1][i],ans_len=len_now; else
			if (f[alls-1][i]<ans){
				ans=f[alls-1][i],ans_len=len_now;
			}
		}
		cout<<"Case "<<cnt<<": "<<ans<<endl;
	}
	return 0;
}