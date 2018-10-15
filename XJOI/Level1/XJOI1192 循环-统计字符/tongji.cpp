#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int lt=0,nm=0,ot=0;
int main(){
	char ch=getchar();
	while (ch!='?'){
		if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) lt++; else
		if (ch>='0'&&ch<='9') nm++; else ot++;
		ch=getchar();
	}
	printf("Letters=%d\nDigits=%d\nOthers=%d\n",lt,nm,ot);
	return 0;
}
