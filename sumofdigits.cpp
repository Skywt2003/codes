/*
 * CodeForces CONTEST 1060
 * B Maximum Sum of Digits
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

int n;

inline int count_number(int x){
	int ret=0;
	while (x) ret+=x%10,x/=10;
	return ret;
}

signed main(){
	n=read();
	int b=0,k=1;
	int ans=0;
	while (b<=n){
		b+=k*9;k++;
		for (int i=0;i<10;i++){
			int nowb=b+i*k;
			ans=max(ans,count_number(nowb)+count_number(n-nowb));
		}
	}
	printf("%lld\n",ans);
	return 0;
}