#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2005;
int n,a[maxn][maxn];
inline bool check(int x,int y){
	if (x<1||y<1|x>n||y>n) return false;
	return true;
}
inline int _abs(int x){
	if (x<0) return -x;
	return x;
}
int main(){
	scanf("%d",&n);int cnt=0,nowmax=0;
	for (int i=2;i<=n*2;i++){
		if (i&1) {
			for (int j=1;j<i;j++) if (check(j,i-j)) a[j][i-j]=++cnt;
		} else{
			for (int j=i-1;j>=1;j--) if (check(j,i-j)) a[j][i-j]=++cnt;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<n;j++) printf("%d ",a[i][j]);
		printf("%d\n",a[i][n]);
	}
	return 0;
}
