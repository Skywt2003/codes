#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

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
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	memset(que,0x80,sizeof(que));

	n=read(); m=read(); q=read(); u=read(); v=read(); t=read();
	head[0]=head[1]=head[2]=1;
	tail[0]=tail[1]=tail[2]=0;
	for (int i=1;i<=n;i++) que[0][++tail[0]]=read();
	sort(que[0]+head[0],que[0]+head[0]+tail[0],compare_greater);

	#ifdef DEBUG
		printf("QUE[0] AFTER SORTING:\n ");
		for (int i=1;i<=n;i++) printf("%lld ",que[0][i]); printf("\n");
	#endif

	for (int i=1;i<=m;i++){
		int now=que[0][head[0]],k=0;
		if (head[1]<=tail[1] && que[1][head[1]] > now) now=que[1][head[1]],k=1;
		if (head[2]<=tail[2] && que[2][head[2]] > now) now=que[2][head[2]],k=2;
		head[k]++;

		int now_real=now+(i-1)*q;
		#ifdef DEBUG
			printf(" now=%lld, k=%lld ,now_real=%lld\n",now,k,now_real);
		#endif
		if (i%t==0) printf("%lld ",now_real);
		int now1=now_real*u/v,now2=now_real-now1;
		que[1][++tail[1]]=now1-i*q;
		que[2][++tail[2]]=now2-i*q;
	}
	printf("\n");

	for (int i=1;i<=n+m;i++){
		int now=que[0][head[0]],k=0;
		if (head[1]<=tail[1] && que[1][head[1]] > now) now=que[1][head[1]],k=1;
		if (head[2]<=tail[2] && que[2][head[2]] > now) now=que[2][head[2]],k=2;
		head[k]++;

		if (i%t==0) printf("%lld ",now+m*q);
	}
	printf("\n");
	
	return 0;
}