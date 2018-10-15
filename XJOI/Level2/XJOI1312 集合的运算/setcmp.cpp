#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10005,maxx=30005;
int n,hsh[maxx];
bool nem1=false,nem2=false,nxtf=false;;
inline int read(){
    if (nxtf) {nxtf=0;return -1;}
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;if (ch==10||ch==13||ch==-1) return -1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    if (ch==10||ch==13||ch==-1) nxtf=1;
	return ret*f;
}
int main(){
    int x=read();
    while (x!=-1){hsh[x]+=1;x=read();nem1=1;}
    while (x==-1) x=read();
    while (x!=-1){hsh[x]+=2;x=read();nem2=1;}
    if ((!nem1)||(!nem2)) {printf("-1\n");return 0;}
    for (int i=1;i<=30000;i++) if (hsh[i]) printf("%d ",i);printf("\n");
    for (int i=1;i<=30000;i++) if (hsh[i]==1) printf("%d ",i);printf("\n");
    for (int i=1;i<=30000;i++) if (hsh[i]==3) printf("%d ",i);printf("\n");
    for (int i=1;i<=30000;i++) if (hsh[i]==1||hsh[i]==2) printf("%d ",i);printf("\n");
    return 0;
}