#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long dp[2][1<<11];//用滚动数组存储轮廓线dp状态数目
int n,m;
int main(){
	while(~scanf("%d %d",&n,&m) && (n || m)){
		if((n&1) && (m&1)){//如果n和m同时为奇数，则直接输出0，不可能铺满
			printf("0\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		if(m>n)swap(m,n);//使得n>m,即窄列
		int h = 1 <<(m-1);//只有最高位为1
		dp[0][(1<<m)-1] = 1;
		int cur = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cur^=1;
				memset(dp[cur],0,sizeof(dp[cur]));
				for(int k = 0; k <(1<<m); k++){
					if(k & h){//[i,j]上面的格子为1，即[i-1,j]已经被填满
						dp[cur][(k^h)<<1]+=dp[cur^1][k];//[i,j]不填充
						if(j && !(k&1)){//[i,j-1]未填充且j不是第一列
							//可以横向填充，即将[i,j-1]与pi,j]填为1
							dp[cur][((k^h)<<1)|3] += dp[cur^1][k];//k^h是为了把k的最高位变成0，移位的时候可以舍掉，其余的位不发生改变(位运算真是666)
						}
					} else {
						if(i)//上面的格子[i-1,j]未被填充，那[i,j]只能竖向填充，否则将永远无法填充到[i-1,j]
							dp[cur][((k&(h-1))<<1)|1] += dp[cur^1][k];//k&(h-1)是为了把k的最高位变成0，移位的时候可以舍掉，其余的位不发生改变(位运算真是666)
					}
				}
			}
		}
		printf("%lld\n",dp[cur][(1<<m)-1]);
	}
	return 0;
}