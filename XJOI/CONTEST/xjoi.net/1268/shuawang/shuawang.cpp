#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=1e9+7;
const int maxn=5e4+5,maxm=25;

int T,n,m,q;

string a,b;

vector<string> vec;

namespace subtask3{
	int f[maxn][2];

	int main(){
		if (a[n-1]=='?') f[n-1][0]=10,f[n-1][1]=1; else
		if (a[n-1]==b[0]) f[n-1][0]=f[n-1][1]=1; else
		f[n-1][0]=1,f[n-1][1]=0;
		for (int i=n-2;i>=0;i--){
			if (a[i]!='?'){
				if (a[i]==b[0]) f[i][1]=f[i+1][0]+f[i+1][1],f[i][0]=f[i][1];
				else f[i][1]=f[i+1][1],f[i][0]=f[i+1][0];
			} else {
				f[i][0]=f[i-1][0]*10;
				f[i][1]=f[i-1][0] + f[i-1][1]*10;
			}
		}

		while (q--){
			int rq=read();
			string ans=a; bool inc=false;
			for (int i=0;i<n;i++){
				if (a[i]=='?'){
					int num=0,j;
					for (j=0;j<=9;j++){
						num+=f[i+1][inc^1];
						if (num>rq) break;
					}
					j--; num-=f[i+1][inc^1];
					ans[i]=j+'0'; rq-=num;
					if (j+'0' == b[0]) inc=true;
					if (num==0) break;
				} else if (a[i]==b[0]) inc=true;
			}
			cout<<ans<<endl;
		}
	}
}

bool flg[maxn];

void DFS(int now,bool did){
	if (now>=m-1 && did==false){
		bool flg=true;
		for (int i=0;i<m;i++) if (a[now-m+i+1]!=b[i]) {flg=false;break;}
		if (flg) did=true;
	}
	if (now==n-1){
		if (did) vec.push_back(a);
		return;
	}

	if (a[now+1]!='?') DFS(now+1,did);
	else {
		for (int i=0;i<10;i++) a[now+1]='0'+i,DFS(now+1,did);
		a[now+1]='?';
	}
}

signed main(){
	T=read();
	while (T--){
		n=read();q=read();
		cin>>b; m=b.length();
		cin>>a;
		
		if (n>7 && m==1){
			subtask3::main();
			continue;
		}
		
		vec.clear();
		DFS(-1,false);
		// for (int i=0;i<vec.size();i++) cout<<vec[i]<<endl;
		// sort(vec.begin(),vec.end());

		while (q--){
			int x=read();
			if (x > vec.size()) printf("-1\n");
			else cout<<vec[x-1]<<endl;
		}
	}
	return 0;
}