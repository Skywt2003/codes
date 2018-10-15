#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n;
string a[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) cout<<a[i]<<"\n";
	return 0;
}
