#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,n,k;

int random(int x){
    return (((int)rand()<<31)+(rand()))%x;
}

signed main(){
    srand(time(NULL));
    T=rand()%5;
    printf("%lld\n",T);
    while (T--){
        n=random(1e3-1)+1,k=random(1e5-1)+1;
        printf("%lld %lld\n",n,k);
        for (int i=1;i<=n;i++) printf("%lld ",random(1e3-1)+1);
        printf("\n");
    }
    return 0;
}