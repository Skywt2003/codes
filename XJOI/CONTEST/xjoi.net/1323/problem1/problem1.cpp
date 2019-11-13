#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;
const int tt=1e9+7;

int n;
int f[maxn][2];

void add_mode(int &x,int y){
	x=(x+y)%tt;
}

signed main(){
	freopen("problem1.in","r",stdin);
	freopen("problem1.out","w",stdout);
	
	n=read();
	f[1][0]=1;
	f[2][0]=f[2][1]=1;
	for (int i=3;i<=n;i++){
		//for (int j=1;j<=i;j++) add_mode(f[i][0],f[i-1][j&1^1]);
		f[i][0]=(f[i-1][0]*((i+1)/2)%tt + f[i-1][1]*(i/2)%tt)%tt;
		//for (int j=1;j<=i;j++) add_mode(f[i][1],f[i-1][j&1]);
		f[i][1]=(f[i-1][0]*(i/2)%tt + f[i-1][1]*((i+1)/2)%tt)%tt;
	}

	printf("The %lld",n);
	if (n%100 >= 10 && n%100 < 20) printf("th"); else
	if (n == 1) printf("st"); else
	if (n == 2) printf("nd"); else
	if (n == 3) printf("rd"); else
	printf("th");
	printf(" answer is %lld.\n",f[n][0]);
	return 0;
}
