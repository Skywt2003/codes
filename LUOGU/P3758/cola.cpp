#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=35,maxt=1e6+5;
const int tt=2017;

int n,e,t;

class matrix{
	private:
		int n,m,a[maxn][maxn];

	public:
		matrix(){
			memset(a,0,sizeof(a));n=m=0;
		}

        void set_value(int x,int y,int v){
            a[x][y]=v;
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

        void set_init(int x,int y,int v){
            n=x;m=y;
            for (int i=0;i<n;i++)
                for (int j=0;j<m;j++)
                    a[i][j]=v;
        }

        int get(int x,int y){
            return a[x][y];
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

matrix trans;
int ans=0;

signed main(){
    n=read(); e=read();
    n++;
    trans.set_unit(n,n);
    for (int i=0;i<e;i++){
        int x=read(),y=read();
        trans.set_value(x,y,1);
        trans.set_value(y,x,1);
    }
    for (int i=1;i<n;i++) trans.set_value(i,0,1);
    t=read();

    trans=trans^t;
    int ans=0;
    for (int i=0;i<n;i++) ans=(ans+trans.get(1,i))%tt;
    printf("%d\n",ans);
    return 0;
}