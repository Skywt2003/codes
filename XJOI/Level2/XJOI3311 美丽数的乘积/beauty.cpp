#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,zs=0,a[maxn],ub=0;
bool fd=false;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){ 
        char ch=getchar();
        while (ch<'0'||ch>'9') ch=getchar();
        int len=0;bool isb=true;
        while (ch>='0'&&ch<='9'){
            len++;
            if ((!fd)&&((len>1&&ch!='0')||(len==1&&ch!='1'))) isb=false,fd=true;
            if (!fd||(fd&&isb==false)) a[len]=ch-'0';
            ch=getchar();
        }
        if (isb) zs+=len-1; else ub=len;
    }
    if (!fd){
        putchar('1');
        for (int i=1;i<=zs;i++) putchar('0');
    } else if (a[1]==0){
        printf("0\n");
    } else {
        for (int i=1;i<=ub;i++) putchar(a[i]+'0');
        for (int i=1;i<=zs;i++) putchar('0');
    }
    return 0;
}