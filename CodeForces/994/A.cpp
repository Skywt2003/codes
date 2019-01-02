#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn=10005;
int n,m;
int num[maxn];
bool a[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&num[i]);
	for (int i=1;i<=m;i++){
		int x;scanf("%d",&x);
		a[x]=true;
	}
	for (int i=1;i<=n;i++) if (a[num[i]]) cout<<num[i]<<" ";
	return 0;
}