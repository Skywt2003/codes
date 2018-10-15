#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int n,m,a[maxn];
bool flg=1;
int main(){
	while (scanf("%d",&n)!=-1){
		flg=1;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&m);
		for (int i=1;i<=n;i++){
			if (a[i]==m&&flg) flg=0; else printf("%d ",a[i]);
		}
	}
	return 0;
}
