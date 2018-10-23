#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

#define int long long
using namespace std;

const int maxn=105;
int n=0,m=0;
int fa[maxn];

int len1,len2;
char a[maxn],b[maxn];
stack <int> s;

signed main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	len1=strlen(a+1);len2=strlen(b+1);

	for (int i=1;i<=len1;i++){
		if (a[i]=='('){
			n++;
			s.push(n);
		} else {
			int now=s.top();
			s.pop();
			fa[now]=s.top();
		}
	}

	for (int i=1;i<=len2;i++){
		if (b[i]=='('){
			m++;
			s.push(m);
		} else {
			int now=s.top();
			s.pop();
			fa[now]=s.top();
		}
	}

		
}