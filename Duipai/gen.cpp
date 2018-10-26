#include <bits/stdc++.h>
using namespace std;

const int maxn=300;
int n;
bool f[maxn][maxn];
int out[maxn];

signed main() {
	srand(time(NULL));
	n=rand() % 10 + 1;
	cout<<n<<endl;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) if (rand()&1) out[i]++; else out[j]++;
	for (int i=1;i<=n;i++) cout<<out[i]<<" ";
	cout<<endl;
	return 0;
}
