#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int day[12]={31,-1,31,30,31,30,31,31,30,31,30,31};
int x,y;
int main(){
	scanf("%d%d",&x,&y);
	if (y!=2) printf("%d\n",day[y-1]); else{
		bool rn=false;
		if (x%1000==0) rn=true; else
		if (x%100==0) rn=false; else
		if (x%4==0) rn=true; else rn=false;
		if (rn) printf("29\n"); else printf("28\n");
	}
	return 0;
}
