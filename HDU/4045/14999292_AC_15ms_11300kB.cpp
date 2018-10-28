#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005,tt=1e9+7;
int n,r,k,m,c[maxn*2][maxn*2],s[maxn][maxn],lst[maxn];
inline void Build(){
    for (int i=0;i<=1000;i++) s[i][i]=1;
    for (int i=1;i<=1000;i++)
        for (int j=1;j<i;j++)
            s[i][j]=(s[i-1][j-1]+(long long)s[i-1][j]*j%tt)%tt;
    c[0][0]=1;
    for (int i=1;i<=1000;i++){
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%tt;
    }
}
inline int C(int x,int y){
    return c[x][y];
}
int main(){
    Build();
    while (scanf("%d%d%d%d",&n,&r,&k,&m)!=-1){
        if (n-((r-1)*k+1)+r<0) {printf("0\n");continue;}
        int sum=0;
        for (int i=1;i<=min(r,m);i++) sum=(sum+s[r][i])%tt;
        printf("%d\n",(long long)C(n-((r-1)*k+1)+r,r)*sum%tt);
    }
    return 0;
}
