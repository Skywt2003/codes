#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=7e6+5;

int n,m,q,u,v,t;

int que[3][maxn];
int head[3],tail[3];

bool compare_greater(int x,int y){
	return x>y;
}

signed main(){
	n=read(); m=read(); q=read(); u=read(); v=read(); t=read();
	head[0]=head[1]=head[2]=1;
	tail[0]=tail[1]=tail[2]=0;
	for (int i=1;i<=n;i++) que[0][++tail[0]]=read();
	sort(que[0]+head[0],que[0]+head[0]+tail[0],compare_greater);

	for (int i=1;i<=m;i++){
		int now=que[0][head[0]],k=0;
		
	}
}