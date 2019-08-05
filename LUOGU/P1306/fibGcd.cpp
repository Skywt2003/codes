#include<bits/stdc++.h>
#define int long long
using namespace std;

const int tt=1e8;

int n,m;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

class matrix{
    private:
	    static const int maxn=55;

    public:
	    int n,m,a[maxn][maxn];

        matrix(){
        	n=m=0;memset(a,0,sizeof(a));
        }

        void set_zero(int x,int y){
        	n=x;m=y;
        	memset(a,0,sizeof(a));
        }

        void set_unit(int x,int y){
        	n=x;m=y;
        	memset(a,0,sizeof(a));
        	for (int i=0;i<min(n,m);i++) a[i][i]=1;
        }

        bool operator ==(matrix &b){
        	if (n!=b.n || m!=b.m) return false;
        	for (int i=0;i<n;i++){
        		for (int j=0;j<n;j++){
        			if (a[i][j]!=b.a[i][j]) return false;
        		}
        	}
        	return true;
        }

        bool operator !=(matrix &b){
        	return !(*this == b);
        }

        matrix operator +(matrix &b){
        	matrix ret;ret.set_zero(n,m);
        	for (int i=0;i<n;i++){
        		for (int j=0;j<m;j++){
        			ret.a[i][j]=(a[i][j]+b.a[i][j])%tt;
        		}
        	}
        	return ret;
        }
           
        matrix operator -(matrix &b){
        	matrix ret;ret.set_zero(n,m);
        	for (int i=0;i<n;i++){
        		for (int j=0;j<m;j++){
        			ret.a[i][j]=(a[i][j]-b.a[i][j]+tt)%tt;
        		}
        	}
        	return ret;
        }

        matrix operator *(matrix &b){
        	matrix ret;ret.set_zero(n,b.m);
        	for (int k=0;k<m;k++){
        		for (int i=0;i<n;i++){
        			for (int j=0;j<b.m;j++){
        				ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j]%tt)%tt;
        			}
        		}
        	}
        	return ret;
        }

        matrix operator ^(int b){
        	matrix ret;ret.set_unit(n,m);
        	matrix w;w=*this;
        	while (b){
        		if (b&1) ret=ret*w;
        		b>>=1;w=w*w;
        	}
        	return ret;
        }
};

int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

signed main(){
    n=read(),m=read();
    n=gcd(n,m);

    matrix now;
    now.n=2,now.m=2;
    now.a[0][0]=now.a[0][1]=now.a[1][0]=1;

    now=now^n;
    printf("%lld\n",now.a[0][1]);
    return 0;
}