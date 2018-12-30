#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,l,wmax,an,bn;
int ans=0;
vector<int> v1,v2;

inline int myabs(int x){
	return (x<0)?-x:x;
}

bool judge(int i,int j){
	if (wmax*(v2[j]-v1[i]+l) > myabs(v2[j]+v1[i]+l)) return true;
	return false;
}

signed main(){
	v1.clear();v2.clear();
	n=read();l=read();wmax=read();
	for (int i=1;i<=n;i++){
		int x=read(),t=read();
		if (t==1) v1.push_back(x); else v2.push_back(x);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	an=(int)v1.size();bn=(int)v2.size();
	for (int i=0;i<an;i++){
		int L=0,R=bn-1;
		int stp=bn;
		while (L<=R){
			int mid=((R-L)>>1)+L;
			if (judge(i,mid)) stp=mid,R=mid-1; else L=mid+1;
		}
		ans+=bn-stp;
		// cout<<"i = "<<i+1<<" and stp = "<<stp+1<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}