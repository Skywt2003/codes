#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

const int maxn=55;
bool s[maxn][maxn];
int n,m,K;

inline void write(){
	printf("%lld %lld\n",n,m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) putchar(s[i][j]?'#':'.');
		printf("\n");
	}
}

signed main(){
	scanf("%lld",&K);K++;
	if (K<100){
		if (K<=50){
			n=1;m=K;
			printf("%lld %lld\n",n,m);
			for (int i=1;i<=m;i++) putchar('.');
		} else {
			n=50;m=K-50+1;
			printf("%lld %lld\n",n,m);
			for (int i=1;i<=n;i++){
				for (int j=1;j<=m;j++)
					putchar((i==1 || j==m)?'.':'#');
				printf("\n");
			}
		}
	} else {
		n=50;m=(K&1)?50:49;
		int cnt=n+m-1;
		memset(s,1,sizeof(s));
		for (int i=1;i<=n;i++) s[i][m]=false;
		for (int i=1;i<=m;i++) s[1][i]=false;
		int now1=3,now2=5;
		while (now1<=n && now2<=n){
			int i=m;
			s[now1+1][m]=true;cnt--;
			while (cnt<K-1){
				i--;if (i<1) break;
				s[now1][i]=s[now2][i]=false;
				cnt+=2;
			}
			if (cnt==K-1){
				s[now1+1][i]=false;
				write();
				return 0;
			} else s[now1+1][1]=false;
			cnt++;
			now1+=4;now2+=4;
		}
	}
	return 0;
}