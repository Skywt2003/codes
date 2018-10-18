#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
bool vis[15];
int main(){
	for (int i=1;i<5;i++)
	for (int j=1;j<10;j++) if (i!=j)
	for (int k=1;k<10;k++) if (i!=k&&j!=k){
		memset(vis,0,sizeof(vis));
		int num=i*100+j*10+k;
		vis[i]=vis[j]=vis[k]=vis[num*2/100]=vis[num*2/10%10]=vis[num*2%10]=vis[num*3/100]=vis[num*3/10%10]=vis[num*3%10]=1;
		bool flg=true;
		for (int z=1;z<=9;z++) if (vis[z]==0){flg=false;break;}
		if (flg) printf("%d %d %d\n",num,num*2,num*3);
	}
	return 0;
}
