#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=506;

int n;
char a[maxn];

int cnt=0,ans1,ans2;

char stk[maxn];
int id[maxn];
int stk_top=0;

signed main(){
	n=read();
	scanf("%s",a+1);

	int cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++) if (a[i]=='(') cnt1++; else cnt2++;
	if (cnt1!=cnt2) {printf("0\n1 1\n");return 0;}

	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			int now=0,q1=0,q2=n; swap(a[i],a[j]);
			stk_top=0;

			for (int k=1;k<=n;k++){
				if (stk_top!=0 && stk[stk_top]=='(' && a[k]==')') stk_top--;
				else stk[++stk_top]=a[k],id[stk_top]=k;
			}
			for (int k=stk_top;k>=1;k--) if (stk[k]==')') {q1=id[k];break;}
			for (int k=1;k<=stk_top;k++) if (stk[k]=='(') {q2=id[k];break;}
			// if (i==7 && j==8) printf("q1=%lld q2=%lld\n",q1,q2);
			stk_top=0;
			for (int k=q1+1;k<=n;k++){
				now+=stk_top==0;
				if (stk_top!=0 && stk[stk_top]=='(' && a[k]==')') stk_top--;
				else stk[++stk_top]=a[k];
			}

			if (now>cnt) cnt=now,ans1=i,ans2=j;
			swap(a[i],a[j]);
		}

	printf("%lld\n%lld %lld\n",cnt,ans1,ans2);
	return 0;
}