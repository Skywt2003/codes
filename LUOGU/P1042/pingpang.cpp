#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int w11,l11,w21,l21,ans1[maxn][2],ans2[maxn][2];
inline char read_ch(){
	char ch=getchar();
	while (ch!='E'&&ch!='W'&&ch!='L') ch=getchar();
	return ch;
}
inline int _abs(int x){
	if (x<0) return -x; else return x;
}
int main(){
	w11=l11=w21=l21=0;
	char ch=read_ch();
	while (1){
		if (ch=='W') w11++,w21++; else
		if (ch=='L') l11++,l21++; else
		if (ch=='E') break;
		if (_abs(w11-l11)>=2&&w11+l11>=11){
			ans1[++ans1[0][0]][0]=w11;
			ans1[ans1[0][0]][1]=l11;
			w11=l11=0;
		}
		if (_abs(w21-l21)>=2&&w21+l21>=21){
			ans2[++ans2[0][0]][0]=w21;
			ans2[ans2[0][0]][1]=l21;
			w21=l21=0;
		}
		ch=read_ch();
	}
	for (int i=1;i<=ans1[0][0];i++) printf("%d:%d\n",ans1[i][0],ans1[i][1]);
	if (w11&&l11) printf("%d:%d\n",w11,l11);
	printf("\n");
	for (int i=1;i<=ans2[0][0];i++) printf("%d:%d\n",ans2[i][0],ans2[i][1]);
	if (w21&&l21) printf("%d:%d\n",w21,l21);
	return 0;
}
