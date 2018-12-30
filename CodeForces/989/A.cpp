#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;
string s;

int main(){
	cin>>s;
	n=s.length();
	for (int i=1;i<n-1;i++){
		if (s[i-1]!='.' && s[i]!='.' && s[i+1]!='.'){
			if (s[i]!=s[i-1] && s[i]!=s[i+1] && s[i-1]!=s[i+1]){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}