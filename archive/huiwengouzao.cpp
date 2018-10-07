/*
 * XJOI CONTEST1000 T2 回文构造机
 * 180919 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

using namespace std;
const int maxn=1005;
int n,hash[305],ans=0;
char s[maxn];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) hash[s[i]]++;
	for (int i=0;i<255;i++) ans+=hash[i]&1;
	if (ans==0){
		printf("1\n");
		for (int i=1;i<255;i++) if (hash[i]){
			for (int j=1;j<=hash[i]/2;j++) putchar(i);
		}
		for (int i=254;i>=1;i--) if (hash[i]){
			for (int j=1;j<=hash[i]/2;j++) putchar(i);
		}
		printf("\n");
		return 0;
	}
	printf("%d\n",ans);
	for (int i=1;i<255;i++) if (hash[i]&1){
		for (int j=1;j<255;j++) if (!(hash[j]&1)){
			for (int k=1;k<=hash[j]/2;k++) putchar(j);
		}
		for (int j=1;j<=hash[i];j++) putchar(i);
		for (int j=254;j>=1;j--) if (!(hash[j]&1)){
			for (int k=1;k<=hash[j]/2;k++) putchar(j);
			hash[j]=0;
		}
		hash[i]=0;
		printf("\n");
		break;
	}
	for (int i=1;i<255;i++) if (hash[i]&1){
		for (int j=1;j<=hash[i];j++) putchar(i);
		printf("\n");
	}
	return 0;
}