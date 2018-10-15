#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) if (i%3==0){
		bool flg=0;int x=i;
		while (x){
			if (x%10==5) {flg=1;break;}
			x/=10;
		}
		if (flg) printf("%d\n",i);
	}
	return 0;
}
