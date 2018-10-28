#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=305,maxe=100005,maxq=100005;
int n,m,q,dst[maxn][maxn],INF;
bool hsh[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void Init(){
	memset(dst,0x3f,sizeof(dst));
	INF=dst[0][0];
	for (int i=0;i<n;i++) dst[i][i]=0;
	memset(hsh,0,sizeof(hsh));
}
inline void Floyd(int k){
	for (int i=0;i<n;i++) if (i!=k)
	for (int j=0;j<n;j++) if (i!=j&&k!=j)
		dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
}
int main(){
	int T=0;
	for (;;){
		n=read();m=read();q=read();
		if (n==0&&m==0&&q==0) break;
		if (T) printf("\n");
		printf("Case %d:\n",++T);
		Init();
		for (int i=0;i<m;i++){
			int x=read(),y=read(),z=read();
			dst[x][y]=min(dst[x][y],z);
		}
		for (int i=0;i<q;i++){
			int f=read();
			if (f==0){
				int x=read();
				if (hsh[x]) printf("ERROR! At point %d\n",x); else hsh[x]=true,Floyd(x);
			} else {
				int x=read(),y=read();
				if ((!hsh[x])||(!hsh[y])) printf("ERROR! At path %d to %d\n",x,y); else
				if (dst[x][y]>=INF) printf("No such path\n"); else
				printf("%d\n",dst[x][y]);
			}
		}
	}
	return 0;
}