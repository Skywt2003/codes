#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn=1e18+1;

inline int random(int x){
	return (((long long)rand()<<31)+((long long)rand()<<15)+((long long)rand()<<1)+((long long)rand()&1))%x;
}

signed main(){
	srand(time(0));
	cout<<random(maxn)<<" "<<random(maxn)<<" "<<random(maxn)<<" "<<random(maxn)<<endl;
	return 0;
}