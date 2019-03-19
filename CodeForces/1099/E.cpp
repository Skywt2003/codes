#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
// #define int long long

const char c[4]={'A','C','G','T'};
const int INF=1e9;

int n,m;
vector<string> a;

struct plan{
	int ch1,ch2,ch3,ch4,md;
	vector<int> cases;
	int cost;
}ans;

signed main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		string s;cin>>s;
		a.push_back(s);
	}
	ans.cost=INF;
	for (int i=0;i<4;i++)
	for (int j=0;j<4;j++) if (i!=j){
		plan now;now.ch1=now.ch2=now.ch3=now.ch4=now.cost=0;now.cases.clear();
		int k=-1,t=-1;
		for (int ww=0;ww<4;ww++) if (ww!=i && ww!=j){if (k==-1) k=ww;else t=ww;}
		now.ch1=i;now.ch2=j;now.ch3=k;now.ch4=t;now.md=0;
		for (int x=0;x<n;x++){
			int now1=0,now2=0;
			for (int y=0;y<m;y++) if ((x&1)==0){ // use i,j
				now1+=(y&1)?(!(c[j]==a[x][y])):(!(c[i]==a[x][y]));
				now2+=(y&1)?(!(c[i]==a[x][y])):(!(c[j]==a[x][y]));
			} else {
				now1+=(y&1)?(!(c[t]==a[x][y])):(!(c[k]==a[x][y]));
				now2+=(y&1)?(!(c[k]==a[x][y])):(!(c[t]==a[x][y]));
			}
			if (now1<now2) now.cases.push_back(0); else now.cases.push_back(1);
			now.cost+=min(now1,now2);
		}
		if (now.cost<ans.cost) ans=now;
		// putchar(c[i]);putchar(c[j]);printf(" cost=%d\n",now.cost);
	}

	for (int i=0;i<4;i++)
	for (int j=0;j<4;j++) if (i!=j){
		plan now;now.ch1=now.ch2=now.ch3=now.ch4=now.cost=0;now.cases.clear();
		int k=-1,t=-1;
		for (int ww=0;ww<4;ww++) if (ww!=i && ww!=j){if (k==-1) k=ww;else t=ww;}
		now.ch1=i;now.ch2=j;now.ch3=k;now.ch4=t;now.md=1;
		for (int y=0;y<m;y++){
			int now1=0,now2=0;
			for (int x=0;x<n;x++) if ((y&1)==0){ // use i,j
				now1+=(x&1)?(!(c[j]==a[x][y])):(!(c[i]==a[x][y]));
				now2+=(x&1)?(!(c[i]==a[x][y])):(!(c[j]==a[x][y]));
			} else {
				now1+=(x&1)?(!(c[t]==a[x][y])):(!(c[k]==a[x][y]));
				now2+=(x&1)?(!(c[k]==a[x][y])):(!(c[t]==a[x][y]));
			}
			if (now1<now2) now.cases.push_back(0); else now.cases.push_back(1);
			now.cost+=min(now1,now2);
		}
		if (now.cost<ans.cost) ans=now;
	}

	if (ans.md==0){
		// printf("Case 1\n");
		int i=ans.ch1,j=ans.ch2,k=ans.ch3,t=ans.ch4;
		for (int x=0;x<n;x++){
			for (int y=0;y<m;y++) if ((x&1)==0){
				if (ans.cases[x]==0) putchar((y&1)?c[j]:c[i]); else
				if (ans.cases[x]==1) putchar((y&1)?c[i]:c[j]);
			} else {
				if (ans.cases[x]==0) putchar((y&1)?c[t]:c[k]); else
				if (ans.cases[x]==1) putchar((y&1)?c[k]:c[t]);
			}
			printf("\n");
		}
	} else {
		int i=ans.ch1,j=ans.ch2,k=ans.ch3,t=ans.ch4;
		for (int x=0;x<n;x++){
			for (int y=0;y<m;y++) if ((y&1)==0){
				if (ans.cases[y]==0) putchar((x&1)?c[j]:c[i]); else
				if (ans.cases[y]==1) putchar((x&1)?c[i]:c[j]);
			} else {
				if (ans.cases[y]==0) putchar((x&1)?c[t]:c[k]); else
				if (ans.cases[y]==1) putchar((x&1)?c[k]:c[t]);
			}
			printf("\n");
		}
	}
	return 0;
}