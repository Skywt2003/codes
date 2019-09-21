#include<bits/stdc++.h>

const int maxlen=105,tt=10000;
using namespace std;

class bigint{
	private:
		int len,a[maxlen/4];

	public:
		// Constructed functions

		bigint(){len=0;memset(a,0,sizeof(a));}
		bigint(int x){
			len=0; memset(a,0,sizeof(a));
			while (x) a[++len]=x%tt,x/=tt;
			for (int i=1;i<len/2;i++) swap(a[i],a[len-i+1]);
		}

		// Special IO functions

		void set_value(int x){
			len=0; memset(a,0,sizeof(a));
			while (x) a[++len]=x%tt,x/=tt;
			for (int i=1;i<len/2;i++) swap(a[i],a[len-i+1]);
		}

		void write(){
			printf("%d",a[len]);
			for (int i=len-1;i>=1;i--) printf("%04d",a[i]);
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
			bigint c(0); c.len=len;
			for (int i=1;i<=c.len;i++){
				c.a[i]+=a[i]-b.a[i]+tt;
				c.a[i+1]+=c.a[i]/tt-1;
				c.a[i]%=tt;
			}
			while (c.a[c.len+1]) c.len++;
			while (c.len>0 && c.a[c.len]==0) c.len--;
			return c;
		}
};

const int maxw=605;

int k,n;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

bigint c[maxw][maxw];

void build_con(){
    c[0][0].set_value(1);
    for (int i=1;i<=(1<<k);i++){
        c[i][0].set_value(1); c[i][i].set_value(1);
        for (int j=1;j<i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
}

signed main(){
    k=read(); n=read();

    build_con();

    bigint ans(0);
    for (int i=2;i<=n/k;i++) ans=ans+c[(1<<k)-1][i];
    for (int i=1;i<=(1<<(n%k))-1;i++) ans=ans+c[(1<<k)-i-1][n/k];
    ans.writeln();
    return 0;
}