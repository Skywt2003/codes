#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;
string f="",g="";

string get_string(int x,int i){
	string ret="("+to_string(x)+"*((1-abs((t-"+to_string(i)+")))+abs((1-abs((t-"+to_string(i)+"))))))";
	return ret;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read(),r=read();
		if (i==1){
			f=get_string(x/2,i);
			g=get_string(y/2,i);
		}else{
			f="("+f+"+"+get_string(x/2,i)+")";
			g="("+g+"+"+get_string(y/2,i)+")";
		}
	}
	cout<<f<<endl<<g<<endl;
	return 0;
}