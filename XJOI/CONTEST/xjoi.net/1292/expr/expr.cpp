#include<bits/stdc++.h>

#define int long long

#define pii pair<int,int>

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1000000;
const int tt=998244353;

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		b>>=1; w=w*w%tt;
	}
	return ret;
}

int inv(int x){
	return qsm(x,tt-2);
}

int n,q,len;
char s[maxn];

int num[maxn],cnt=0;
char sym_num[maxn];
int blt[maxn];

pii block[maxn];
int tot=0;
char sym_block[maxn];

int pre[maxn],suf[maxn];
bool isz[maxn];
int zeros=0,sum;

signed main(){
	n=read(),q=read();
	scanf("%s",s+1); len=strlen(s+1);
	
	block[++tot].first=++cnt; sym_block[tot]='+';
	for (int i=1;i<=len;i++) if (s[i]=='+' || s[i]=='-'){
		if (tot>=1) block[tot].second=cnt;
		block[++tot].first=++cnt; sym_block[tot]=s[i];
		sym_num[cnt]='*';
	} else if (s[i]=='*' || s[i]=='/'){
		cnt++; sym_num[cnt]=s[i];
	} else {
		int j=i; num[cnt]=s[j]-'0';
		while (j+1<=len && s[j+1]>='0' && s[j+1]<='9')
			num[cnt]=num[cnt]*10+s[j+1]-'0',j++;
		if (sym_num[cnt]=='/'){
			if (num[cnt]==0) isz[cnt]=true,zeros++;
			num[cnt]=inv(num[cnt]);
		}
		blt[cnt]=tot;
		i=j;
	}
	block[tot].second=cnt;

	for (int i=1;i<=tot;i++){
		pre[block[i].first]=num[block[i].first];
		for (int j=block[i].first+1;j<=block[i].second;j++)
			pre[j]=pre[j-1]*num[j]%tt;
		
		suf[block[i].second]=num[block[i].second];
		for (int j=block[i].second-1;j>=block[i].first;j--)
			suf[j]=suf[j+1]*num[j]%tt;
		
		if (sym_block[i]=='+' || i==1) sum=(sum+pre[block[i].second])%tt;
		else sum=(sum-pre[block[i].second]+tt)%tt;
	}
	
	while (q--){
		int x=read(),y=read()%tt;
		zeros-=isz[x];
		if (zeros>0 || (y==0 && sym_num[x]=='/')){
			printf("Invalid\n");
		} else {
			if (sym_num[x]=='/') y=inv(y);
			int tmp=pre[block[blt[x]].second];
			int flg=(sym_block[blt[x]]=='+')?1:-1;
			int now=(sum - flg*tmp + flg*((x-1>=block[blt[x]].first)?pre[x-1]:1)*((x+1<=block[blt[x]].second)?suf[x+1]:1)%tt*y%tt + tt)%tt;
			printf("%lld\n",now);
		}
		zeros+=isz[x];
	}
	
	return 0;
}
