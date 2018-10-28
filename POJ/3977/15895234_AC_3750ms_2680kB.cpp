#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const long long maxn=40,maxs=400005,INF=(long long)1e15+100;
long long n,sl,sr,m;
long long a[maxn];

struct Element{
	long long num,count;
};
Element s[maxs],ans;

inline long long Abs(long long x){
	return x<0?-x:x;
}

inline bool compare(Element aa,Element bb){
	return (aa.num<bb.num)||((aa.num==bb.num)&&(aa.count<bb.count));
}

inline Element find(long long x){
	long long L=1,R=m;
	Element ret;
	ret.num=INF;ret.count=0;
	while (L<=R){
		long long mid=((R-L)>>1)+L;
		if ((Abs(s[mid].num+x)<ret.num)||(Abs(s[mid].num+x)==ret.num&&s[mid].count<ret.count)) ret=(Element){Abs(s[mid].num+x),s[mid].count};
		if (s[mid].num<-x) L=mid+1; else R=mid-1;
	}
	return ret;
}

inline void make_right(){
	m=0;
	for (long long i=1;i<sr;i++){
		long long now_sum=0,now_cnt=0;
		for (long long j=0;j<n/2;j++) if (i&(1<<j)) now_sum+=a[n-j],now_cnt++;
		s[++m]=(Element){now_sum,now_cnt};
	}
}

inline void make_left(){
	sort(s+1,s+1+m,compare);
	ans.num=INF;ans.count=0;
	for (long long i=0;i<sl;i++){
		long long now_sum=0,now_cnt=0;
		for (long long j=0;j<n-(n/2);j++) if (i&(1<<j)) now_sum+=a[j+1],now_cnt++;
		Element f=find(now_sum);
		if ((f.num<ans.num)||((f.num==ans.num)&&(f.count+now_cnt<ans.count))) ans=(Element){f.num,f.count+now_cnt};
		if (now_cnt==0) continue;
		if ((Abs(now_sum)<ans.num)||((Abs(now_sum)==ans.num)&&(now_cnt<ans.count))) ans=(Element){Abs(now_sum),now_cnt};
	}
}

int main(){
	while (~scanf("%lld",&n)){
		if (n==0) break;
		for (long long i=1;i<=n;i++) scanf("%lld",&a[i]);
		sr=(long long)1<<(n/2);
		sl=(long long)1<<(n-(n/2));
		make_right();
		make_left();
		printf("%lld %lld\n",ans.num,ans.count);
	}
	return 0;
}