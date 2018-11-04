#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;

const int N=998244353;
int T;
int n,m,k,x;
const int yinzi[96]={1,2,4,7,8,14,16,17,28,32,34,56,64,68,112,119,128,136,224,238,256,272,448,476,512,544,896,952,1024,1088,1792,1904,2048,2176,3584,3808,4096,4352,7168,7616,8192,8704,14336,15232,16384,17408,28672,30464,32768,34816,57344,60928,65536,69632,114688,121856,131072,139264,229376,243712,262144,278528,458752,487424,524288,557056,917504,974848,1048576,1114112,1835008,1949696,2097152,2228224,3670016,3899392,4194304,4456448,7340032,7798784,8388608,8912896,14680064,15597568,17825792,29360128,31195136,35651584,58720256,62390272,71303168,124780544,142606336,249561088,499122176,998244352};

vector<int> vec;
map<int,int> id;
int cnt=0,ans,now,lst;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int qsm(int a,int b){
	int ret=1,w=a%n;
	while (b){
		if (b&1) ret=ret*w%n;
		w=w*w%n;b>>=1;
	}
	return ret;
}

inline int solve(int n,int m,int x,int k){
	int len=-1;
	for (int i=0;i<96;i++) if (qsm(k,yinzi[i])==1) {len=yinzi[i];break;}
	if (!(len&1)) return ((m<=len/2)?(n-m):(n-len/2)); else return ((m<=len-1)?(n-m):(n-len+1));
}

signed main(){
	T=read();
	while (T--){
		n=read();m=read();
		x=read();k=read();
		printf("%lld\n",solve(n,m,x,k));
	}
	return 0;
}