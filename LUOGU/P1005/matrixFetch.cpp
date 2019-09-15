#include<bits/stdc++.h>

const int maxlen=110,tt=10000;
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
};

bigint max(bigint x,bigint y){
    if (x>y) return x; else return y;
}

void swap(bigint &a,bigint &b){
	bigint tmp;
	tmp=a,a=b,b=tmp;
}

int get_num(int m,int i,int j){
    return m-j+i;
}

int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=105;

int n,m;

int a[maxn][maxn];
bigint f[maxn][maxn];
bigint qsm2[maxn];

signed main(){
    n=read(); m=read();
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
        a[i][j]=read();

    qsm2[0].set_value(1);
    for (int i=1;i<=m;i++) qsm2[i]=qsm2[i-1]*2;

    bigint ans(0);
    for  (int l=1;l<=n;l++){
        f[1][m].set_value(0);
        for (int L=m-2;L>=0;L--)
        for (int i=1;i<=m-L;i++){
            int j=i+L;
            bigint delta1,delta2;
            f[i][j].set_value(0);
            if (i-1>=1){
                delta1=qsm2[get_num(m,i-1,j)]*a[l][i-1];
                delta1=f[i-1][j]+delta1;
                f[i][j]=max(f[i][j],delta1);
            }
            if (j+1<=m){
                delta2=qsm2[get_num(m,i,j+1)]*a[l][j+1];
                delta2=f[i][j+1]+delta2;
                f[i][j]=max(f[i][j],delta2);
            }
        }
        bigint now(0);
        for (int i=1;i<=m;i++){
            bigint delta=qsm2[m]*a[l][i];
            delta=f[i][i]+delta;
            now=max(now,delta);
        }
        ans=ans+now;
    }

    ans.writeln();
    return 0;
}