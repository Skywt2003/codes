#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long n,k,l,m;
struct Matrix{
    long long a[3][3];
    void Init(){
        memset(a,0,sizeof(a));
        a[0][0]=a[1][0]=a[0][1]=1;
        a[1][1]=0;
    }
    void Clear(){
        memset(a,0,sizeof(a));
    }
    Matrix operator *(Matrix b){
        Matrix c; c.Clear();
        for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
        for (int k=0;k<2;k++)
            c.a[i][j]=((long long)c.a[i][j]+(long long)a[i][k]*b.a[k][j])%m;
        return c;
    }
    Matrix operator ^(long long b){
        Matrix ret; ret.Init();
        Matrix w;   w.Clear();
        for (int i=0;i<2;i++)
        for (int j=0;j<2;j++) w.a[i][j]=a[i][j];
        while (b){
            if (b%2) ret=ret*w;
            b=b/2;w=w*w;
        }
        return ret;
    }
};
inline long long qsm(long long a,long long b){
    long long ret=1,w=a;
    while (b){
        if (b%2) ret=(ret*w)%m;
        b=b/2;w=(w*w)%m;
    }
    return ret;
}
inline long long GetFib(long long x){
    Matrix a; a.Init();
    a=a^n;
    return a.a[0][0]%m;
}
int main(){
    scanf("%lld%lld%lld%lld",&n,&k,&l,&m);
    if (l<63&&k>=((long long)1<<l)){printf("0\n");return 0;}
    long long f=GetFib(n),ans=1;
	for(int i=0;i<l;i++){
		if ((i>=63)||(k&((long long)1<<(long long)i))==0) ans=(ans*f)%m; else
		ans=((long long)ans*(qsm(2,n)-f)%m)%m;
	}
    printf("%lld\n",(ans+m)%m);
    return 0;
}