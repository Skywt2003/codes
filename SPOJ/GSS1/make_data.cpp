#include<bits/stdc++.h>

using namespace std;

const int maxx=100,half_maxx=50;
int n=7,m=6;

int main(){
	srand(time(NULL));
	cout<<n<<endl;
	for (int i=1;i<=n;i++) cout<<rand()%maxx-half_maxx<<" ";
	cout<<endl<<m<<endl;
	for (int i=1;i<=m;i++){
		int x=rand()%n+1,y=rand()%n+1;
		if (x>y) swap(x,y);
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}