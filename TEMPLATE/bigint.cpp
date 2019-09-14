// 190914

#include<bits/stdc++.h>

const int maxlen=10010,tt=10000;
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
};

bigint read(){
	bigint ret; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9'){
		bigint now; now=(ch-'0');
		ret=ret*10; ret=ret+now;
		ch=getchar();
	}
	return ret;
}

void swap(bigint &a,bigint &b){
	bigint tmp;
	tmp=a,a=b,b=tmp;
}

bigint max(bigint x,bigint y){
    if (x>y) return x; else return y;
}

bigint qsm(int a,int b){
    bigint ret; ret.set_value(1);
    bigint w; w.set_value(a);
    while (b){
        if (b&1) ret=ret*w;
        b>>=1; w=w*w;
    }
    return ret;
}
