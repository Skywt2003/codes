#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int tt=10000;
int n;
struct Matrix{
    int a[3][3];
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
            c.a[i][j]=((long long)c.a[i][j]+(long long)a[i][k]*b.a[k][j])%tt;
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
    void Write(){
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++) printf("%d ",a[i][j]);
            printf("\n");
        }
    }
};
int main(){
    scanf("%d",&n);n--;
    while (n!=-2){
        if (n==-1) printf("0\n"); else{
            Matrix a; a.Init();
            a=a^n;
            printf("%d\n",a.a[1][0]);
        }
        scanf("%d",&n);n--;
    }
    return 0;
}