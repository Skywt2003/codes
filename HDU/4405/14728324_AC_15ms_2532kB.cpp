#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100010;
int n,m,nxt[maxn];
double f[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();m=read();
    while (n!=0||m!=0){
        memset(f,0,sizeof(f));
        memset(nxt,255,sizeof(nxt));
        for (int i=1;i<=m;i++){
            int x=read(),y=read();
            nxt[x]=y;
        }
        for (int i=n-1;i>=0;i--){
            if (nxt[i]==-1){
                for (int j=i+1;j<=i+6;j++) f[i]+=f[j]/6.0;
                f[i]+=1.0;
            } else f[i]=f[nxt[i]];
        }
        printf("%.4f\n",f[0]);
        n=read();m=read();
    }
    return 0;
}
