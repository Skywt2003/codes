#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define max(x,y) ((x)<(y)?(y):(x))
#define min(x,y) ((x)>(y)?(y):(x))
using namespace std;

const int maxn=40005;
int n,q,d[maxn],l[maxn];
int L,R,x,now,ans;

template<class T>inline void read(T &x) {
    x=0;T f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-48,ch=getchar();
    x*=f;
}

int main(){
	read(n);read(q);
	for (int i=1;i<=n;++i) read(d[i]);
	for (int i=1;i<=n;++i) read(l[i]);
	while (q--){
		read(L);read(R);read(x);
		now=x,ans=x;
		for (int i=L;i<=R;++i){
			if (l[i]<=x){now=x;continue;}
			now=min(now+d[i],l[i]);
			if (now>ans) ans=now;
		}
		printf("%d\n",ans);
	}
	return 0;
}