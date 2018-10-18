#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define percent(x) if(rand()%100<x)


using namespace std;

ll Rand(ll mod){return (unsigned long long)rand()*rand()*rand()*rand()%mod;}
const int base=2;
int Rand_log(int ub){return pow(base,1.0*rand()/RAND_MAX*(log(ub)/log(base)));}

const int maxl=700;
const int s=26;

struct Substance{
	bool hidden;
	int cnt[s];
	Substance():hidden(0){memset(cnt,0,sizeof(cnt));}
	Substance(int _p):hidden(_p<0){
		if (_p<0) return;
		bool flag=0;
		for (int i=0;i<s;++i)percent(_p){
			cnt[i]=rand()%9+1;
			flag=1;
		}
		if (!flag){
			int index=rand()%s;
			cnt[index]=rand()%9+1;
		}
	}
	Substance(int _p,int *top):hidden(0){
		bool flag=0;
		for (int i=0;i<s;++i)percent(_p){
			if (!top[i]) continue;
			cnt[i]=rand()%min(top[i],9)+1;
			flag=1;
		}
		if (!flag){
			int index=rand()%s;
			for (int i=0;i<50&&!top[index];++i) index=rand()%s;
			cnt[index]=rand()%max(1,min(top[index],9))+1;
		}
	}
	void renew(){
		bool flag=0;
		for (int i=0;i<s;++i)if (cnt[i]>0){flag=1;break;}
		if (!flag) cnt[rand()%s]=rand()%2+1;
		for (int i=0;i<s;++i){
			cnt[i]=min(cnt[i],9);
			cnt[i]=max(cnt[i],0);
		}
	}
	int check(){
		bool flag=0;
		for (int i=0;i<s;++i)if (cnt[i]>0){flag=1;break;}
		if (!flag) return -1;
		for (int i=0;i<s;++i)if (cnt[i]<0||cnt[i]>9) return 0;
		return 1;
	}
	void print(int type){
		if (hidden){
			if (type<0) printf("No Solution");
			else putchar('?');
			return;
		}
		if (type<0) type=0;
		bool flag=0;
		for (int i=0;i<s;++i)if (cnt[i]>0){flag=1;break;}
		if (!flag) cnt[rand()%s]=rand()%2+1;
		for (int i=0;i<s;++i){
			cnt[i]=min(cnt[i],9);
			cnt[i]=max(cnt[i],0);
			if (cnt[i]==1){
				if (type%2) printf("%c%d",char(i+'A'),cnt[i]);
				else printf("%c",char(i+'A'));
			}
			else if (cnt[i]==0){
				if (type/2) printf("%c%d",char(i+'A'),cnt[i]);
			}
			else printf("%c%d",char(i+'A'),cnt[i]);
		}
	}
};
inline Substance operator +(Substance u,Substance v){
	Substance ret;
	for (int i=0;i<s;++i) ret.cnt[i]=u.cnt[i]+v.cnt[i];
	return ret;
}
inline Substance operator -(Substance u,Substance v){
	Substance ret;
	for (int i=0;i<s;++i) ret.cnt[i]=u.cnt[i]-v.cnt[i];
	return ret;
}

void boom(){
	for (;;);
}

typedef vector<Substance> Vector;

void print(Vector &v,int type){
	bool _first=1;
	int index=0;
	for (auto ele:v){
		++index;
		if (index>1) putchar('+');
		ele.print(type);
	}
}

const int maxSize=6;
Vector l,r;
Substance ans[233];
void gen(int n,int m,int Q,int L,int R,int testid){
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;++i){
		if (testid>=16&&i==1){
			Substance tmp(50);
			tmp.print(m);
			printf("=?+");
			tmp.print(m);
			puts("");
			ans[1].hidden=1;
			continue;
		}
		int sizeL=L?1:sqrt(rand()%int(pow(maxSize+1,2)-1)+1);
		int sizeR=R?1:sqrt(rand()%int(pow(maxSize+1,2)-1)+1);
		l.clear();
		r.clear();
		percent(3){
			for (int i=0;i<sizeL;++i) l.pb(Substance(rand()%100));
			for (int i=0;i<sizeR;++i) r.pb(Substance(rand()%100));
			if (!Q){
				percent(50) swap(l,r);
				l[rand()%int(l.size())].hidden=1;
				percent(50) swap(l,r);
			}
		}
		else{
			Substance sum=Substance();
			int _p=rand()%77+7;
			for (int i=0;i<sizeL;++i){
				Substance tmp(_p);
				sum=sum+tmp;
				l.pb(tmp);
			}
			for (int i=0;i<sizeR-1;++i){
				Substance tmp(_p,sum.cnt);
				sum=sum-tmp;
				r.pb(tmp);
			}
			r.pb(sum);
			bool flag=0;
			if (!Q&&!L&&!R) percent(37){
				if (sizeL<maxSize) l.pb(Substance(-1)),flag=1;
				else if (sizeR<maxSize) r.pb(Substance(-1)),flag=1;
			}
			if (!Q&&!flag){
				percent(50) swap(l,r);
				l[rand()%int(l.size())].hidden=1;
				percent(50) swap(l,r);
			}
		}
		
		random_shuffle(l.begin(),l.end());
		random_shuffle(r.begin(),r.end());
		if (L&&l.size()>1) swap(l,r);
		if (R&&r.size()>1) swap(l,r);
		if (L&&l.size()>1) boom();
		if (Q) l[0].hidden=1;
		Substance sum=Substance();
		int side=1;
		for (Vector::iterator it=l.begin();it!=l.end();++it)
			if (!it->hidden) it->renew(),sum=sum+(*it);
		for (Vector::iterator it=r.begin();it!=r.end();++it)
			if (!it->hidden) it->renew(),sum=sum-(*it);
			else side=0;
		if (side) sum=Substance()-sum;
		int res=sum.check();
		if (res<1){
			if (res==0){
				percent(57){--i;continue;}
				if (testid>=4) percent(57){--i;continue;}
				if (testid>=8) percent(57){--i;continue;}
				if (testid>=12) percent(47){--i;continue;}
				if (testid>=16) percent(77){--i;continue;}
			}
			if (res==-1) percent(17){--i;continue;}
			ans[i].hidden=1;
		}
		else ans[i]=sum;
		
		print(l,m);
		putchar('=');
		print(r,m);
		puts("");
/*		if (!R&&i==8){
			for (int j=0;j<s;++j) printf("%d ",r[3].cnt[j]);
			printf("%d\n",int(r[3].hidden));
		}*/
	}
}

int main(int argc,char **argv){
	unsigned int seed=argc>1?atoi(argv[1]):time(0);
	srand(seed);
	freopen("seed.txt","w",stdout);
	printf("%u\n",seed);
	fclose(stdout);
	const int cas=20;
	const int maxn=100;
	for (int t=0;t<cas;++t){
		char fname[23];
		sprintf(fname,"%d.in",t+1);
		freopen(fname,"w",stdout);
		gen(maxn,t%4,t<16,t<8,t<4||(8<=t&&t<12),t);
		fclose(stdout);
		sprintf(fname,"%d.ans",t+1);
		freopen(fname,"w",stdout);
		for (int i=1;i<=maxn;++i,puts("")) ans[i].print(-1);
		fclose(stdout);
	}
	return 0;
}
