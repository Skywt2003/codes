#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=99999+5;
int n,a[maxn];
vector<int> num1,num4,num6;
bool vis[maxn];

struct ans{
	int x,y,z;
};
vector<ans> answer;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) if (a[i]==1) num1.push_back(i); else
							if (a[i]==4) num4.push_back(i); else
							if (a[i]==6) num6.push_back(i);
	int p1=0,p4=0,p6=0;
	for (int i=1;i<=n;i++){
		if (p4<num4.size()) while (num4[p4]<i && p4<num4.size()) p4++;
		if (p6<num6.size()) while (num6[p6]<i && p6<num6.size()) p6++;
		if (a[i]==2){
			if ((p4>=num4.size())&&(p6>=num6.size()) || p1>=num1.size() || num1[p1]>i){
				printf("-1\n");
				return 0;
			}
			if (p4>=num4.size()) answer.push_back((ans){1,2,6}),vis[num1[p1]]=vis[i]=vis[num6[p6]]=true,p1++,p6++;
			else answer.push_back((ans){1,2,4}),vis[num1[p1]]=vis[i]=vis[num4[p4]]=true,p1++,p4++;
		} else if (a[i]==3){
			if (p6>=num6.size() || p1>num1.size() || num1[p1]>i){
				printf("-1\n");
				return 0;
			}
			answer.push_back((ans){1,3,6});
			vis[num1[p1]]=vis[i]=vis[num6[p6]]=true;
			p1++;p6++;
		}
		// cout<<i<<endl;
	}
	for (int i=1;i<=n;i++) if (vis[i]==false){
		printf("-1\n");
		return 0;
	}
	for (int i=0;i<answer.size();i++) printf("%lld %lld %lld\n",answer[i].x,answer[i].y,answer[i].z);
	return 0;
}