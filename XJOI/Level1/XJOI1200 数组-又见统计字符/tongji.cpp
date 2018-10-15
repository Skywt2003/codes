#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=30;
int hsh[maxn];
int main(){
	char ch=getchar();
	while (ch!=-1){
		if (ch>='a'&&ch<='z') hsh[ch-'a']++;
		ch=getchar();
	}
	for (int i=0;i<26;i++) if (hsh[i]) printf("%c:%d\n",i+'a',hsh[i]);
	return 0;
}
