#include<bits/stdc++.h>

//#define int long long

using namespace std;

inline int read()
{
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int l,r,h,t;

signed main()
{ 
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	l=read(),r=read(),h=read(),t=read();
	if (t!=0){printf("-1\n");return 0;}
	if (l>0){printf("-1\n");return 0;}
	printf("%.2lf\n",sqrt(2.0*9.8*h));
	return 0;
}
