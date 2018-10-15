#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105,tt=1000000007;;
int n;
long long m;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
struct Matrix{
    int a[maxn][maxn];
    void ReadMatrix(){
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) a[i][j]=read();
    }
    void Init(){
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++) a[i][i]=1;
    }
    void Clear(){
        memset(a,0,sizeof(a));
    }
    Matrix operator *(Matrix b){
        Matrix c; c.Clear();
        for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        for (int k=0;k<n;k++)
            c.a[i][j]=((long long)c.a[i][j]+(long long)a[i][k]*b.a[k][j])%tt;
        return c;
    }
    Matrix operator ^(long long b){
        Matrix ret; ret.Init();
        Matrix w;   w.Clear();
        for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) w.a[i][j]=a[i][j];
        while (b){
            if (b%2) ret=ret*w;
            b=b/2;w=w*w;
        }
        return ret;
    }
    void Write(){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++) printf("%d ",a[i][j]);
            printf("\n");
        }
    }
};
int main(){
    n=read();scanf("%lld",&m);
    Matrix a; a.ReadMatrix();
    // printf("Read part finished.\n");
    a=a^m;
    a.Write();
    return 0;
}