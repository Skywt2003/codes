#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000005;
int n,phi[maxn],prm[maxn];
bool flg[maxn];
inline void Build_Eular(){
    memset(flg,1,sizeof(flg));
    flg[1]=false;
    for (int i=2;i<=n;i++){
        if (flg[i]){
            prm[++prm[0]]=i;
            phi[i]=i-1;
        }
        for (int j=1;j<=prm[0];j++){
            if (i*prm[j]>n) break;
            flg[i*prm[j]]=0;
            if (i%prm[j]==0){
                phi[i*prm[j]]=phi[i]*prm[j];
                break;
            } else phi[i*prm[j]]=phi[i]*(prm[j]-1);
        }
    }
}
int main(){
    scanf("%d",&n);
    Build_Eular();
    long long sum=0;
    for (int i=1;i<=n;i++) sum+=phi[i];
    printf("%lld\n",sum);
    return 0;
}