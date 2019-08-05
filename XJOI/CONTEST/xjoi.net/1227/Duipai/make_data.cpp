#include<bits/stdc++.h>
#include<Windows.h>

using namespace std;

int n,m;

signed main(){
    srand(GetTickCount());
    n=5,m=5;
    printf("%d %d\n",n,m);
    for (int i=1;i<=n;i++) printf("%d ",rand()%15); printf("\n");
    for (int i=1;i<=m;i++) printf("%d\n",rand()%10-5);
    return 0;
}