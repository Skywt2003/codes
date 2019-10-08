#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1000005;
const int zero=5,N=10000;

int n;

const int tt=1e9+7;

class matrix{
	static const int maxn=55;
	private:
		int n,m,a[maxn][maxn];

	public:
		matrix(){
			memset(a,0,sizeof(a));n=m=0;
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

        int * const operator [](const int x){
            return a[x];
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

		int count_sum(){
			int ret=0;
			for (int i=0;i<n;i++){
				for (int j=0;j<m;j++){
					ret=(ret+a[i][j])%tt;
				}
			}
			return ret;
	}
};

int get_answer(int x){
    if (x&1) return 0;
    x/=2;
    if (x==0) return 1; else
    if (x==1) return 1; else
    if (x==2) return 4;
    matrix trans; trans.set_zero(3,3);
    trans[0][0]=1; trans[0][1]=1; trans[0][2]=0;
    trans[1][0]=3; trans[1][1]=0; trans[1][2]=1;
    trans[2][0]=2; trans[2][1]=0; trans[2][2]=1;

    matrix now; now.set_zero(1,3);
    now[0][0]=4; now[0][1]=1; now[0][2]=1;
    // trans=trans^(x-2);
    // now=now*trans;
    x-=3;
    trans=trans^x;
    now=now*trans;
    return (now[0][0]+now[0][1]*3%tt+now[0][2]*2%tt)%tt;
}

signed main(){
    while (~scanf("%lld",&n)) printf("%lld\n",get_answer(n));
    return 0;
}