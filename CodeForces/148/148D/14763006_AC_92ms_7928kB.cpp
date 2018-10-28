#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,m;
double f[maxn][maxn];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) f[i][0]=1.0; // 如果等到公主拿，只剩白鼠，那公主肯定赢
    for (int i=0;i<=n;i++){ // F[i][j]: 等到公主拿，袋子里还剩下i只白鼠j只黑鼠，公主赢的概率
        for (int j=1;j<=m;j++){ // 枚举黑鼠  drg(Dragon):当时龙赢的几率
            f[i][j]=(double)i/(i+j); // 考虑公主直接赢的情况
            double drg=(double)j*(double)(j-1)/(i+j)/(i+j-1); // 公主没有赢，龙继续拿也没有赢的情况
            if (j>=3) f[i][j]+=drg*(double)(j-2)/(i+j-2)*f[i][j-3]; // 跑出来的两只都是黑鼠，公主继续拿，赢了的概率
            if (i>=1&&j>=2) f[i][j]+=drg*(double)i/(i+j-2)*f[i-1][j-2]; // 跑出来一只黑一只白，...
        }
    }
    printf("%.10f\n",f[n][m]);
    return 0;
}
