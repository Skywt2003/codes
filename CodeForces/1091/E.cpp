#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5e5+5;

int n,flg=0;
int a[maxn],s[maxn];

pair<int,bool> d[maxn];

// bool cmp(pair<int,bool> xx,pair<int,bool> yy){
// 	return xx.first>yy.first;
// }

bool cmp(int x,int y){
	return x>y;
}

int check(int now){
	int delta=0;
	for (int i=1;i<=n;i++){
		if (delta==0 && a[i]<now) d[i].first=now,d[i].second=true,delta=1;
		d[i+delta].first=a[i],d[i+delta].second=false;
	}
	if (delta==0) d[n+1].first=now,d[n+1].second=true;
	n++;
	for (int i=1;i<=n;i++) s[i]=s[i-1]+d[i].first;
	int rt=n+1;
	bool onr=false;
	for (int k=1;k<=n;k++){
		if (d[k].second) onr=false;
		if (rt<k+1) rt=k+1;
		while (rt-1>k && d[rt-1].first<=k){
			if (d[rt-1].second) onr=true;
			rt--;
		}
		int lft=s[k];
		int rgt=k*(k-1)+((rt-1)-(k+1)+1)*k+(s[n]-s[rt-1]);
		if (lft>rgt){
			n--;
			if (onr) return -1; else return 1;
		}
	}
	n--;
	return 0;
}

signed main(){
	n=read();
	int sum=0;
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	sort(a+1,a+1+n,cmp);
	flg=sum&1;
	int x=-1,y=-1;
	int L=0,R=(sum+1)/2;
	while (L<=R){
		int mid=(((R-L)>>1)+L)*2+flg;
		int f=check(mid);
		if (f==0) x=mid,R=mid/2-1; else
		if (f==1) R=mid/2-1; else
		L=mid/2+1;
	}
	L=0,R=(sum+1)/2;
	while (L<=R){
		int mid=(((R-L)>>1)+L)*2+flg;
		int f=check(mid);
		if (f==0) y=mid,L=mid/2+1; else
		if (f==-1) L=mid/2+1; else
		R=mid/2-1;
	}
	for (int i=x;i<=y;i+=2) printf("%lld ",i);
	printf("\n");
	// printf("! %lld\n",check(3));
	return 0;
}