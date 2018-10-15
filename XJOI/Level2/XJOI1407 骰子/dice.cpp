#include<cstdio>
#include<cstring>
using namespace std;
int n,lft,rght,up,dwn,frt,bhd,ans=0;
int main(){
	up=1;dwn=6;lft=4;rght=3;frt=2;bhd=5;
	ans+=up;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char a[10];
		scanf("%s",a);
		int tmp;
		if (a[0]=='N'){tmp=up;up=frt;frt=dwn;dwn=bhd;bhd=tmp;} else
		if (a[0]=='S'){tmp=up;up=bhd;bhd=dwn;dwn=frt;frt=tmp;} else
		if (a[0]=='E'){tmp=up;up=lft;lft=dwn;dwn=rght;rght=tmp;} else
		if (a[0]=='W'){tmp=up;up=rght;rght=dwn;dwn=lft;lft=tmp;} else
		if (a[0]=='L'){tmp=frt;frt=lft;lft=bhd;bhd=rght;rght=tmp;} else
		if (a[0]=='R'){tmp=frt;frt=rght;rght=bhd;bhd=lft;lft=tmp;}
		ans+=up;
	}
	printf("%d\n",ans);
	return 0;
}