#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,t=0;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
       d=a+b+c;
       if (t) printf("\n");
       printf("%d\n",d);
       t=1;
    }
    return 0;
}
