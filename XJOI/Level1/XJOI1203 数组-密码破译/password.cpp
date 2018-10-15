#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105;
int main(){
	char ch=getchar();
	while (ch!=-1){
		if (ch>='a'&&ch<='z'){
			if (ch=='z') putchar('a'); else putchar(ch+1);
		} else putchar(ch);
		ch=getchar();
	}
	return 0;
}
