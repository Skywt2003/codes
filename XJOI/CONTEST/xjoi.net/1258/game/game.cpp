#include<bits/stdc++.h>
using namespace std;

// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005;
int n,a[maxn],b[maxn];

struct segment{
    int x,y,k;
};
vector<segment> vec;

struct mybitset{
	static const int maxn=70,maxm=30;
	int set[maxn];

	void clear(){
		memset(set,0,sizeof(set));
	}

	bool operator [](int index){
		index--;
		return (set[index/maxm]>>index%maxm)&1;
	}

	void set_value(int index,int value){
		index--;
		if (value) set[index/maxm]|=(int)1<<index%maxm; else set[index/maxm]&=~((int)1<<index%maxm);
	}

	void merge(mybitset &b){
		for (int i=0;i<maxn;i++) set[i]|=b.set[i];
	}

    int popcount(int x){
        int ret=0;
        while (x) ret+=x&1,x>>=1;
        return ret;
    }

	int count(){
		int ret=0;
		for (int i=0;i<maxn;i++) ret+=__builtin_popcount(set[i]);
		return ret;
	}
};

vector<mybitset> grp[maxn];
vector<int> ans[maxn];

bool compare_k(segment aa,segment bb){
    return aa.k < bb.k;
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++) b[i]=read();
    sort(a+1,a+1+n); sort(b+1,b+1+n);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            vec.push_back((segment){i,j,b[j]-a[i]});
    sort(vec.begin(),vec.end(),compare_k);

    for (int i=0,j;i<vec.size();i=j+1){
        mybitset now; now.clear();
        j=i; now.set_value(vec[i].x,1); now.set_value(vec[i].y+n,1);
        while (j+1<vec.size() && vec[j+1].k==vec[i].k) j++,now.set_value(vec[j].x,1),now.set_value(vec[j].y+n,1);

        int tot=j-i+1;
        grp[tot].push_back(now);
        ans[tot].push_back(vec[i].k);

        for (int j=0;j<grp[n-tot].size();j++){
            mybitset nxt=now;
            nxt.merge(grp[n-tot][j]);
            if (nxt.count()==2*n){
                printf("%d %d\n",vec[i].k,ans[n-tot][j]);
                return 0;
            }
        }
    }
    return 0;
}