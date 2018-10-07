/*
 * Vjudge CONTEST 239393
 * LightOJ 1073
 * H - DNA Sequence
 * 181004 By SkyWT
 */

#pragma GCC optimize(3)

#include<cstdio>
#include<iostream>
#include<cstring>
// #include<string>
// #include<cmath>
#include<algorithm>
#include<vector>
// #include<queue>
// #include<stack>
// #include<map>

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

const int maxn=16,maxs=32768+2,maxlen=2005;

int T,n,alls,len[maxn];
string s[maxn];
string forp[maxn][maxn];
bool use[maxn];
vector <string> vec;
vector <int> vlen;
int lst[maxs];

inline int char_to_num(char ch){
	return ch=='A'?1:(ch=='C'?2:(ch=='G'?3:(ch=='T'?4:-1)));
}

inline char num_to_char(int num){
	return num==1?'A':(num==2?'C':(num==3?'G':(num==4?'T':'?')));
}

struct string_num{
	int a[maxlen];
	string_num(){memset_clear(a);}

	void operator =(string s){
		a[0]=0;
		int len=s.length();
		for (int i=0;i<len;i+=15){
			a[0]++;
			for (int j=i;j<min(i+15,len);j++){
				a[a[0]]=a[a[0]]*5+char_to_num(s[j]);
			}
		}
	}
	string tostr()const{
		string s="";
		vector <int> now;
		int tmp[maxlen];
		tmp[0]=a[0];
		for (int i=1;i<=a[0];i++) tmp[i]=a[i];
		for (int i=1;i<=tmp[0];i++){
			now.clear();
			while (tmp[i]) now.push_back(tmp[i]%5),tmp[i]/=5;
			reverse(now.begin(),now.end());
			for (int j=0;j<now.size();j++) s+=num_to_char(now[j]);
		}
		return s;
	}

	int length(){
		string s=tostr();
		return s.length();
	}
	string_num operator +(string_num b){
		string s1=tostr();
		string s2=b.tostr();
		s1=s1+s2;
		string_num ret;ret=s1;
		return ret;
	}
	string_num operator +(string b){
		string s1=tostr();
		s1=s1+b;
		string_num ret;ret=s1;
		return ret;
	}
	bool operator ==(string_num b)const{
		if (a[0]!=b.a[0]) return false;
		for (int i=1;i<=a[0];i++) if (a[i]!=b.a[i]) return false;
		return true;
	}
	bool operator ==(string b)const{
		string s1=tostr();
		return s1==b;
	}
	bool operator <(string_num b)const{
		string s1=tostr();
		string s2=b.tostr();
		return s1<s2;
	}
	bool operator >(string_num b)const{
		string s1=tostr();
		string s2=b.tostr();
		return s1>s2;
	}
	void init(){
		memset_clear(a);
		a[0]=-1;
	}
};

string_num f[maxs];

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
	for (int i=1;i<alls;i++) f[i].init();
}

signed main(){
	// string_num test;
	// test=(string)"ACCATACCATACCATACCAT";
	// cout<<test.tostr()<<endl;

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
		for (int i=0;i<n;i++) f[1<<i]=vec[i],lst[1<<i]=i;
		for (int i=1;i<alls;i++)
			for (int j=0;j<n;j++) if (!(i&(1<<j))){
				string_num now=f[i];int l=lst[i];
				if (now.a[0]==-1) continue;
				now=now+forp[l][j];
				if (f[i+(1<<j)].a[0]==-1) f[i+(1<<j)]=now,lst[i+(1<<j)]=j; else {
					int len1=now.length(),len2=f[i+(1<<j)].length();
					if (len1>len2) continue;
					else if (len1<len2) f[i+(1<<j)]=now,lst[i+(1<<j)]=j;
					else if (f[i+(1<<j)]>now) f[i+(1<<j)]=now,lst[i+(1<<j)]=j;
				}
			}

		cout<<"Case "<<cnt<<": "<<f[alls-1].tostr()<<endl;
	}
	return 0;
}