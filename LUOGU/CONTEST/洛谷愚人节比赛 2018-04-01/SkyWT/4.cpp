#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a,b;
int main(){
    scanf("%d%d",&a,&b);
    int ans=a+b;
    if (ans>32767) ans-=2*32768;
    printf("%d\n",ans);
    return 0;
}
