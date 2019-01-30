#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;
#define int long long

int T;

int n,m;

double prob_pts[10005];
map<string,double> team_pts;
map<string,double> person_pts;
map<string,double>::iterator it;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool check(int x){
	for (int i=2;i<=sqrt(x);i++) if (x%i==0) return false;
	return true;
}

inline void make_prob_pts(){
	for (int i=1000;i<=9999;i++) if (prob_pts[i]==0.0){
		if (check(i)) prob_pts[i]=1.0; else prob_pts[i]=0.3;
	}
}

inline bool cmp(int x,int y){return x>y;}
inline bool cmp_pts(pair<string,double> x,pair<string,double> y){return x.second>y.second;}

signed main(){
	T=read();
	while (T--){
		memset(prob_pts,0,sizeof(prob_pts));
		team_pts.clear();person_pts.clear();

		n=read();m=read();int num;
		num=read();
		for (int i=1;i<=num;i++){int x=read();prob_pts[x]=2.5;}
		num=read();
		for (int i=1;i<=num;i++){int x=read();prob_pts[x]=1.5;}
		make_prob_pts();

		num=read();
		for (int i=1;i<=num;i++){
			string now;int team_rank;double dp=0.0;
			cin>>now>>team_rank;
			if (team_rank==1) dp=36.0; else if (team_rank==2) dp=27.0; else if (team_rank==3) dp=18.0;
			team_pts[now]=dp;
		}

		for (int i=1;i<=n;i++){
			string name,tname,sex;int n1,n2;vector<int> vec;vec.clear();
			cin>>name>>tname>>sex>>n1>>n2;
			person_pts[name]=team_pts[tname];
			if (sex=="F") person_pts[name]+=33.0;
			for (int j=1;j<=n1;j++) person_pts[name]+=prob_pts[read()];
			for (int j=1;j<=n2;j++) vec.push_back(read());
			sort(vec.begin(),vec.end(),cmp);
			if (vec.size()>=3) person_pts[name]+=max(0.0,((double)vec[2]-1200.0)/100.0)*1.5;
		}

		vector<pair<string,double> > vec;vec.clear();
		for (it=person_pts.begin();it!=person_pts.end();it++){
			vec.push_back(*it);
		}
		sort(vec.begin(),vec.end(),cmp_pts);
		for (int i=0;i<m;i++) cout<<vec[i].first<<" ",printf("%.3lf\n",vec[i].second);
	}
	return 0;
}