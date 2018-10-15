#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=50;
int n,m,num,ans[maxn];
inline int read(){
    int ret=0;char ch=getchar();
    while ((ch<'0'||ch>'9')&&(ch<'A'||ch>'F')) ch=getchar();
    while ((ch>='0'&&ch<='9')||(ch>='A'&&ch<='F')){
        int now;
        if (ch>='0'&&ch<='9') now=ch-'0'; else now=ch-'A'+10;
        ret=ret*n+now;
        ch=getchar();
    }
    return ret;
}
inline void write(int x){
    if (x<=9) printf("%d",x); else putchar(x-10+'A');
}
int main(){
    scanf("%d",&n);
    num=read();
    scanf("%d",&m);
    while (num){
        ans[++ans[0]]=num%m;
        num/=m;
    }
    for (int i=ans[0];i>=1;i--) write(ans[i]);
    printf("\n");
    return 0;
}