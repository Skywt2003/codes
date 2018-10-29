#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=10;
int n;

signed main(){
	srand(time(NULL));
	n=rand()%maxn+1;
	cout<<n<<endl;
	for (int i=1;i<=n;i++) cout<<rand()%8<<" ";
	cout<<endl;
	return 0;
}