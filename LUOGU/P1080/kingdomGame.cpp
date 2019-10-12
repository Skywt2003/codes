#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;

const int maxlen=4004,tt=10;
using namespace std;

class bigint{
	private:
		int len,a[maxlen];

	public:
		// Constructed functions

		bigint(){len=0;memset(a,0,sizeof(a));}
		bigint(int x){
			len=0; memset(a,0,sizeof(a));
			while (x) a[++len]=x%tt,x/=tt;
		}

		// Special IO functions

		void set_value(int x){
			len=0; memset(a,0,sizeof(a));
			while (x) a[++len]=x%tt,x/=tt;
		}

		void write(){
			for (int i=len;i>=1;i--) printf("%lld",a[i]);
		}

		void writeln(){
			write();printf("\n");
		}

		// Comparison operations

		bool operator ==(bigint &b){
			if (len!=b.len) return false;
			for (int i=1;i<=len;i++) if (a[i]!=b.a[i]) return false;
			return true;
		}

		bool operator !=(bigint &b){
			return !((*this)==b);
		}

		bool operator ==(int b){
			bigint bb(b);
			return (*this)==bb;
		}

		bool operator !=(int b){
			return !((*this)==b);
		}

		bool operator <(bigint &b){
			if ((*this).len < b.len) return true; else if ((*this).len > b.len ) return false;
			for (int i=len;i>=1;i--) if ((*this).a[i] < b.a[i]) return true; else if ((*this).a[i] > b.a[i]) return false;
			return false;
		}

		bool operator >(bigint &b){
			return !((*this)<b || (*this)==b);
		}

		bool operator <=(bigint &b){
			return ((*this)<b || (*this)==b);
		}

		bool operator >=(bigint &b){
			return ((*this)>b || (*this)==b);
		}

		// Compute operator

		bigint operator +(bigint &b){
			bigint c(0); c.len=max(len,b.len);
			for (int i=1;i<=c.len;i++){
				c.a[i]+=a[i]+b.a[i];
				c.a[i+1]+=c.a[i]/tt;
				c.a[i]%=tt;
			}
			while (c.a[c.len+1]) c.len++;
			while (c.len>0 && c.a[c.len]==0) c.len--;
			return c;
		}

		bigint operator -(bigint &b){
			// printf("Start to sub: ");write();printf(" - ");b.writeln();
			bigint c(0); c.len=len;
			for (int i=1;i<=c.len;i++){
				c.a[i]+=a[i]-b.a[i]+tt;
				c.a[i+1]+=c.a[i]/tt-1;
				c.a[i]%=tt;
			}
			while (c.a[c.len+1]) c.len++;
			while (c.len>0 && c.a[c.len]==0) c.len--;
			// printf(" = ");c.writeln();
			return c;
		}

		bigint operator *(int b){
			bigint c; c.len=len;
			for (int i=1;i<=c.len;i++){
				c.a[i]+=a[i]*b;
				c.a[i+1]+=c.a[i]/tt;
				c.a[i]%=tt;
			}
			while (c.a[c.len+1]) c.len++;
			while (c.len>0 && c.a[c.len]==0) c.len--;
			return c;
		}

		bigint operator *(bigint b){
			bigint c; c.len=len+b.len-1;
			for (int i=1;i<=len;i++)
				for (int j=1;j<=b.len;j++){
					c.a[i+j-1]+=a[i]*b.a[j];
					c.a[i+j]+=c.a[i+j-1]/tt;
					c.a[i+j-1]%=tt;
				}
			while (c.a[c.len+1]) c.len++;
			while (c.len>0 && c.a[c.len]==0) c.len--;
			return c;
		}

		bigint operator /(int b){
			for (int i=1;i<=len/2;i++) swap(a[i],a[len-i+1]);
			bigint c; c.len=len;
			int now=0;
			for (int i=1;i<=c.len;i++){
				now+=a[i];
				c.a[i]=now/b;
				now=now%b*tt;
			}
			for (int i=1;i<=len/2;i++) swap(a[i],a[len-i+1]);
			for (int i=1;i<=c.len/2;i++) swap(c.a[i],c.a[c.len-i+1]);
			while (c.len>0 && c.a[c.len]==0) c.len--;
			return c;
		}
};

bigint read_bigint(){
	bigint ret; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9'){
		bigint now; now=(ch-'0');
		ret=ret*10; ret=ret+now;
		ch=getchar();
	}
	return ret;
}

bigint max(bigint x,bigint y){
	if (x>y) return x; else return y;
}

int n;

struct node{
	bigint first;
	int second;
	bigint third;
}a[maxn];

bigint ans;

bool compare_third(node aa,node bb){
	return aa.third < bb.third;
}

signed main(){
	n=read(); n++;
	for (int i=1;i<=n;i++) a[i].first=read_bigint(),a[i].second=read(),a[i].third=a[i].first*a[i].second;
	sort(a+2,a+1+n,compare_third);

	bigint now; now=a[1].first;
	bigint ans; ans.set_value(0);
	for (int i=2;i<=n;i++){
		bigint tmp; tmp=now/a[i].second;
		ans=max(ans,tmp); now=now*a[i].first;
	}
	ans.writeln();

	return 0;
}