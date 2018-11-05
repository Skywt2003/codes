#include<bits/stdc++.h>

using namespace std;

const int maxx=1,maxc=7;
int n=20,m=20;

int main(){
	srand(time(NULL));
	cout<<n<<" "<<m<<" "<<10000007<<endl;
	for (int i=1;i<=n;i++) cout<<rand()%maxx<<" "; cout<<endl;
	for (int i=1;i<=m;i++){
		int opt=rand()%3+1;cout<<opt<<" ";
		if (opt==1 || opt==2){
			int x=rand()%n+1,y=rand()%n+1;
			if (x>y) swap(x,y);
			cout<<x<<" "<<y<<" "<<rand()%maxc<<endl;
		} else {
			int x=rand()%n+1,y=rand()%n+1;
			if (x>y) swap(x,y);
			cout<<x<<" "<<y<<endl;
		}
	}
	return 0;
}