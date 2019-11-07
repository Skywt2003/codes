#include<bits/stdc++.h>

//#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=8+5,maxm=75,maxs=256+10; // Only for subtask #1 and #2
const int tt=1e9+7;

int n,m,alls;
int f[maxm][maxs];

int st[maxn];

vector<int> lnk[maxs];

void build_edges(){
	for (int i=0;i<alls;i++){
		set<string> s; s.clear();
		for (int j=0;j<i;j++) if ((i&j)==j){ // j is a subset of s
			string now="";
			for (int k=0;k<n;k++) if (j&(1<<k)) now+=(char)st[k];
			if (s.count(now)) continue;
			s.insert(now); lnk[i].push_back(j);
		}
	}
}

signed main(){
	n=read();m=read(); alls=1<<n;
	for (int i=0;i<n;i++) st[i]=read();
	
	build_edges();
	for (int i=0;i<alls;i++) f[0][i]=1;
	for (int i=1;i<m;i++)
		for (int j=0;j<alls;j++){
			f[i][j]=f[i-1][j];
			for (int k=0;k<lnk[j].size();k++)
				f[i][j]=(f[i][j]+f[i-1][lnk[j][k]])%tt;
		}
	printf("%d\n",f[m-1][alls-1]);
	return 0;
}
