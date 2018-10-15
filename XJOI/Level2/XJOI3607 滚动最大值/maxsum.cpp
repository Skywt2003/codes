#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=1000005,tt=1000000007;
int n,m,seed;
long long sum=0;
struct WT{
    int x,id;
    bool operator <(const WT b)const{
        return x<b.x;
    }
};
priority_queue <WT> heap;
int main(){
    scanf("%d%d%d",&n,&m,&seed);
    seed%=tt;
    WT now;
    for (int i=1;i<m;i++){
        int xx=((long long)seed*i)%tt;
        now.x=xx;now.id=i;
        heap.push(now);
    }
    for (int i=m;i<=n;i++){
        int L=i-m+1;
        now.x=((long long)seed*i)%tt;now.id=i;
        heap.push(now);
        while (heap.top().id<L) heap.pop();
        sum=sum+heap.top().x;
    }
    printf("%lld\n",sum);
    return 0;
}