#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;
int n,ans=1,first=1;

string s,now;

signed main(){
	n=read();
	int zero=0;s="1";
	char ch=getchar();while (ch<'0'||ch>'9') ch=getchar();
	for (int i=1;i<=n;i++){
		now="";bool flg=true,hav1=false;int zn=0;
		while (ch>='0'&&ch<='9'){
			now=now+ch;
			if (ch!='0' && ch!='1'){
				flg=false;
			} else if (ch=='1'){
				if (hav1) flg=false; else hav1=true;
			} else zn++;
			ch=getchar();
		}
		if (flg && zn==1 && hav1==false){
			cout<<0<<endl;
			return 0;
		}
		if (flg) zero+=zn; else s=now;
		if (i==n) break;
		while (ch<'0'||ch>'9') ch=getchar();
	}
	cout<<s;
	for (int i=1;i<=zero;i++) putchar('0');
	printf("\n");
	return 0;
}