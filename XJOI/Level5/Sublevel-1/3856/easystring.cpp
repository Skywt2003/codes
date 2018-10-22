#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=1055;
int n;
char a[maxn];

signed main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	int l1=-1,l2=-1,l3=-1,rs=-1;
	for (int i=1;i<=n;i++) if (a[i]=='N') rs=i;
	for (int i=1;i<=n;i++) if (a[i]=='S'){
		if (l1==-1) l1=i;
	} else if (a[i]=='A'){
		if (l1!=-1 && l2==-1) l2=i;
	} else if (a[i]=='T'){
		if (l2!=-1 && l3==-1) l3=i;
	}
	if (l1==-1||l2==-1||l3==-1){
		for (int i=1;i<=n;i++) putchar(a[i]);
		printf("SANTA\n");
	} else if (rs==-1){
		printf("SANTA");
		for (int i=1;i<=n;i++) putchar(a[i]);
		printf("\n");
	} else if (l3>rs){
		for (int i=1;i<=rs;i++) putchar(a[i]);
		printf("SANTA");
		for (int i=rs+1;i<=n;i++) putchar(a[i]);
		printf("\n");
	} else {
		for (int i=1;i<=n;i++) putchar(a[i]);
		printf("TA\n");
	}
	return 0;
}