#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long s,t,g;
inline long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    long long r=exgcd(b,a%b,x,y),t=x;
    x=y;y=t-a/b*y;
    return r;
}
int main(){
	long long x,y,m,n,L;
	while (scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L)!=-1){
	    if (m<n){swap(m,n);swap(x,y);}
	    g=exgcd(m-n,L,s,t);
	    y-=x;
	    if (y%g) printf("Impossible\n"); else{
	    	long long ans=y/g*s;
	    	ans=(ans%L+L)%L;
	    	printf("%lld\n",ans);
	    }
    }
    return 0;
}