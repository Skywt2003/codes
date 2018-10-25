#include <bits/stdc++.h>
using namespace std;

const int maxn=300;
int n;

signed main() {
	srand(time(NULL));
	int T=rand()%10;
	cout<<T<<endl;
	while (T--){
		n=rand()%10+1;
		cout<<n<<endl;
		for (int i=1;i<=n;i++) cout<<rand()%5+1<<" ";
		cout<<endl;
	}
	return 0;
}
