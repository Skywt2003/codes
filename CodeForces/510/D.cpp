#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>

using namespace std;

const int maxn=305;
int INF;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,N;
pair<int,int> a[maxn];
int f[maxn][maxn*maxn];

int num[maxn*maxn];
map<int,int> key;

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i].first=read();
	for (int i=1;i<=n;i++) a[i].second=read();

	N=1;num[1]=0;key[0]=1;

	memset(f,63,sizeof(f));INF=f[0][0];
	f[0][key[0]]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			int lN=N;
			for (int k=1;k<=lN;k++) if (f[j-1][k]!=INF){
				int nxt=gcd(a[i].first,num[k]);
				if (key[nxt]==0) N++,num[N]=nxt,key[nxt]=N;
				int keynxt=key[nxt];
				if (f[j-1][k]+a[i].second<f[j][keynxt]) f[j][keynxt]=f[j-1][k]+a[i].second;
			}
		}
	}

	int ans=INF,st=key[1];
	if (st) for (int i=1;i<=n;i++) if (f[i][st]<ans) ans=f[i][st];
	printf("%d\n",(ans==INF)?-1:ans);
	return 0;
}