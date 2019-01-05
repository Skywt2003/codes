#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
#define int long long

const int maxn=65;
const int maxx=20005;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,m;
int x[maxn],y[maxn];
struct cut{
	int x,y;
	double mid;
};
vector<cut> v;
map<double,int> pre,sum;
map<double,int>::iterator it;

const int zero=10003;
bool apdx[maxx],apdy[maxx];

inline bool cmp(cut aa,cut bb){
	return aa.mid<bb.mid;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) x[i]=read();
	for (int i=1;i<=m;i++) y[i]=read();
	sort(x+1,x+1+n);sort(y+1,y+1+m);
	for (int i=1;i<=n;i++){
		memset(apdy,0,sizeof(apdy));
		for (int j=1;j<=m;j++){
			pre[(1.0*x[i]+1.0*y[j])/2.0]+=(!apdx[x[i]+zero])+(!apdy[y[j]+zero]);
			apdy[y[j]+zero]=true;
		}
		apdx[x[i]+zero]=true;
	}
	int max_num=0;double max_pos=-1.0;
	for (it=pre.begin();it!=pre.end();it++){
		if ((*it).second > max_num){
			max_num=(*it).second;
			max_pos=(*it).first;
		}
	}
	cout<<"First Time:"<<max_num<<endl<<"Last Time:";
	// cout<<"Max_pos = "<<max_pos<<endl;
	memset(apdx,0,sizeof(apdx));
	memset(apdy,0,sizeof(apdy));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if ((1.0*x[i]+1.0*y[j])/2.0 == max_pos){
				apdx[x[i]+zero]=apdy[y[j]+zero]=true;
			}
		}
	}
	for (int i=1;i<=n;i++) if (i==1 || apdx[x[i]+zero]==false || x[i]!=x[i-1]){
		for (int j=1;j<=m;j++) if ((1.0*x[i]+1.0*y[j])/2.0 != max_pos && (j==1 || apdy[y[j]+zero]==false || y[j]!=y[j-1])){
			sum[(1.0*x[i]+1.0*y[j])/2.0]+=(!apdx[x[i]+zero])+(!apdy[y[j]+zero]);
		}
	}
	int ans=max_num;
	for (it=sum.begin();it!=sum.end();it++){
		ans=max(ans,max_num+ ((*it).second));
		// cout<<"ID="<<(*it).first<<", Value="<<(*it).second<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
